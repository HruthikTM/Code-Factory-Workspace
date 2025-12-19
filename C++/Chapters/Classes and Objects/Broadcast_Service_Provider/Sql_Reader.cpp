#include "Sql_Reader.h"
#include "Service_Provider.h"
#include <sqlite3.h>
#include <iostream>

Sql_Reader::Sql_Reader()
{
    cout << "SQL Reader Constructor" << endl;
}

Sql_Reader::~Sql_Reader()
{
    cout << "SQL Reader Destructor" << endl;
}

static int callback([[maybe_unused]] void* data, [[maybe_unused]] int argc,[[maybe_unused]] char** argv, [[maybe_unused]] char** azColName)
{
    return 0;
}

void Sql_Reader::createFile()
{
    sqlite3* db;
    char* errMsg = nullptr;
    int rc = sqlite3_open("broadcast.db", &db);

    if (rc)
    {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        return;
    }

    const char* createServiceProviderTable =
        "CREATE TABLE IF NOT EXISTS service_providers ("
        "serviceProviderId INTEGER PRIMARY KEY, "
        "serviceProviderName TEXT NOT NULL);";

    const char* createLanguageTable =
        "CREATE TABLE IF NOT EXISTS language ("
        "languageId INTEGER PRIMARY KEY, "
        "languageName TEXT NOT NULL);";

    const char* createCategoryTable =
        "CREATE TABLE IF NOT EXISTS category ("
        "categoryId INTEGER PRIMARY KEY, "
        "categoryName TEXT NOT NULL);";

    const char* createChannelsTable =
        "CREATE TABLE IF NOT EXISTS channels ("
        "channelId INTEGER PRIMARY KEY, "
        "channelName TEXT NOT NULL, "
        "serviceProviderId INTEGER, "
        "languageId INTEGER, "
        "categoryId INTEGER, "
        "FOREIGN KEY(serviceProviderId) REFERENCES service_providers(serviceProviderId), "
        "FOREIGN KEY(languageId) REFERENCES language(languageId), "
        "FOREIGN KEY(categoryId) REFERENCES category(categoryId));";

    const char* createProgramsTable =
        "CREATE TABLE IF NOT EXISTS programs ("
        "programId INTEGER PRIMARY KEY, "
        "programTitle TEXT NOT NULL, "
        "startTime TEXT NOT NULL, "
        "endTime TEXT NOT NULL, "
        "channelId INTEGER, "
        "FOREIGN KEY(channelId) REFERENCES channels(channelId));";

    const char* tables[] = { createServiceProviderTable, createLanguageTable, createCategoryTable, createChannelsTable, createProgramsTable};

    for (const char* sql : tables)
    {
        rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
        if (rc != SQLITE_OK)
        {
            cerr << "SQL error: " << errMsg << endl;
            sqlite3_free(errMsg);
        }
    }

    sqlite3_close(db);
    cout << "Database tables created successfully\n";
}

void Sql_Reader::loadLanguages(map<int, string>& languageMap)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    if (sqlite3_open("broadcast.db", &db) != SQLITE_OK)
    {
        cerr << "Cannot open database for languages: " << sqlite3_errmsg(db) << endl;
        return;
    }

    const char* sql = "SELECT languageId, languageName FROM language;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            languageMap[id] = name;
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void Sql_Reader::loadCategories(map<int, string>& categoryMap)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    if (sqlite3_open("broadcast.db", &db) != SQLITE_OK)
    {
        cerr << "Cannot open database for categories: " << sqlite3_errmsg(db) << endl;
        return;
    }

    const char* sql = "SELECT categoryId, categoryName FROM category;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0);
            string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            categoryMap[id] = name;
        }
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void Sql_Reader::readFile(map<int, Channels*>& m_channel, map<int, string>& languageMap, map<int, string>& categoryMap)
{
    loadLanguages(languageMap);
    loadCategories(categoryMap);

    sqlite3* db;
    sqlite3_stmt* stmt;
    const int serviceProviderId = 123;

    const char* sql =
        "SELECT c.channelId, c.channelName, c.languageId, c.categoryId, "
        "p.programId, p.programTitle, p.startTime, p.endTime "
        "FROM channels c "
        "LEFT JOIN programs p ON c.channelId = p.channelId "
        "WHERE c.serviceProviderId = ? "
        "ORDER BY c.channelId;";

    if (sqlite3_open("broadcast.db", &db) != SQLITE_OK)
    {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        return;
    }

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
    {
        cerr << "Failed to prepare query: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return;
    }

    sqlite3_bind_int(stmt, 1, serviceProviderId);

    int lastChannelId = -1;
    Channels* currentChannel = nullptr;

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int channelId = sqlite3_column_int(stmt, 0);
        string channelName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        int langId = sqlite3_column_int(stmt, 2);
        int catId = sqlite3_column_int(stmt, 3);

        if (channelId != lastChannelId)
        {
            currentChannel = new Channels(channelId, channelName);
            m_channel[channelId] = currentChannel;
            lastChannelId = channelId;

            cout << "Loaded Channel: " << channelName
                 << " | Language: " << languageMap[langId]
                 << " | Category: " << categoryMap[catId] << endl;
        }

        if (sqlite3_column_type(stmt, 4) != SQLITE_NULL)
        {
            int programId = sqlite3_column_int(stmt, 4);
            string programTitle = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
            string startTime = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
            string endTime = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

            if (!currentChannel->isProgramIdPresent(programId))
                currentChannel->createProgram(programId, programTitle, startTime, endTime);
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    cout << "All channels and programs loaded successfully.\n";
}

void Sql_Reader::insertChannel(int channelId, const string& channelName, int serviceProviderId, int languageId, int categoryId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    const char* sql =
        "INSERT INTO channels (channelId, channelName, serviceProviderId, languageId, categoryId) "
        "VALUES (?, ?, ?, ?, ?);";

    if (sqlite3_open("broadcast.db", &db) == SQLITE_OK)
    {
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, channelId);
            sqlite3_bind_text(stmt, 2, channelName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 3, serviceProviderId);
            sqlite3_bind_int(stmt, 4, languageId);
            sqlite3_bind_int(stmt, 5, categoryId);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
}

void Sql_Reader::updateChannel(int channelId, const string& newChannelName, int languageId, int categoryId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql =
        "UPDATE channels SET channelName=?, languageId=?, categoryId=? WHERE channelId=?;";

    if (sqlite3_open("broadcast.db", &db) == SQLITE_OK)
    {
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_text(stmt, 1, newChannelName.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 2, languageId);
            sqlite3_bind_int(stmt, 3, categoryId);
            sqlite3_bind_int(stmt, 4, channelId);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
}

void Sql_Reader::insertProgram(int programId, const string& programTitle, const string& startTime, const string& endTime, int channelId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    const char* sql =
        "INSERT INTO programs (programId, programTitle, startTime, endTime, channelId) "
        "VALUES (?, ?, ?, ?, ?);";

    if (sqlite3_open("broadcast.db", &db) == SQLITE_OK)
    {
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, programId);
            sqlite3_bind_text(stmt, 2, programTitle.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 3, startTime.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 4, endTime.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 5, channelId);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
}

void Sql_Reader::updateProgram(int programId, const string& programTitle, const string& startTime, const string& endTime)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    const char* sql =
        "UPDATE programs SET programTitle = ?, startTime = ?, endTime = ? "
        "WHERE programId = ?;";

    if (sqlite3_open("broadcast.db", &db) == SQLITE_OK)
    {
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_text(stmt, 1, programTitle.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 2, startTime.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_text(stmt, 3, endTime.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_int(stmt, 4, programId);

            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
}


void Sql_Reader::deleteChannel(int channelId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM channels WHERE channelId=?;";

    if (sqlite3_open("broadcast.db", &db) == SQLITE_OK)
    {
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, channelId);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
}

void Sql_Reader::deleteProgram(int programId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM programs WHERE programId=?;";

    if (sqlite3_open("broadcast.db", &db) == SQLITE_OK)
    {
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, programId);
            sqlite3_step(stmt);
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }
}

pair<int, int> Sql_Reader::getChannelLanguageCategory(int channelId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    int langId = 0, catId = 0;

    if (sqlite3_open("broadcast.db", &db) == SQLITE_OK)
    {
        const char* sql = "SELECT languageId, categoryId FROM channels WHERE channelId = ?;";
        if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_int(stmt, 1, channelId);
            if (sqlite3_step(stmt) == SQLITE_ROW)
            {
                langId = sqlite3_column_int(stmt, 0);
                catId = sqlite3_column_int(stmt, 1);
            }
            sqlite3_finalize(stmt);
        }
        sqlite3_close(db);
    }

    return make_pair(langId, catId);
}

