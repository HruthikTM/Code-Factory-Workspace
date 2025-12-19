#include "SqlReader.h"
#include <iostream>

using namespace std;

SqlReader* SqlReader::instance = nullptr;

SqlReader::SqlReader() {}

SqlReader::~SqlReader() {}

SqlReader* SqlReader::getInstance()
{
    if (instance == nullptr)
        instance = new SqlReader();
    return instance;
}

int SqlReader::callback(void*, int, char**, char**)
{
    return 0;
}

bool SqlReader::createFile()
{
    sqlite3* db;
    char* errMsg = nullptr;
    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
    {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    const char* tables[] = {
        "CREATE TABLE IF NOT EXISTS language ("
        "languageId INTEGER PRIMARY KEY, "
        "languageName TEXT NOT NULL);",

        "CREATE TABLE IF NOT EXISTS channels ("
        "channelId INTEGER PRIMARY KEY, "
        "channelName TEXT NOT NULL, "
        "price REAL NOT NULL, "
        "languageId INTEGER, "
        "FOREIGN KEY(languageId) REFERENCES language(languageId));",

        "CREATE TABLE IF NOT EXISTS programs ("
        "programId INTEGER PRIMARY KEY, "
        "programTitle TEXT NOT NULL, "
        "startTime TEXT NOT NULL, "
        "endTime TEXT NOT NULL, "
        "channelId INTEGER, "
        "FOREIGN KEY(channelId) REFERENCES channels(channelId));",

        "CREATE TABLE IF NOT EXISTS packages ("
        "packageId INTEGER PRIMARY KEY, "
        "packageName TEXT NOT NULL, "
        "totalPrice REAL NOT NULL);",

        "CREATE TABLE IF NOT EXISTS package_channels ("
        "packageId INTEGER, "
        "channelId INTEGER, "
        "FOREIGN KEY(packageId) REFERENCES packages(packageId) ON DELETE CASCADE, "
        "FOREIGN KEY(channelId) REFERENCES channels(channelId) ON DELETE CASCADE);"
    };

    for (const char* sql : tables)
    {
        if (sqlite3_exec(db, sql, callback, nullptr, &errMsg) != SQLITE_OK)
        {
            cerr << "SQL error creating table: " << errMsg << endl;
            sqlite3_free(errMsg);
            errMsg = nullptr;
        }
    }

    sqlite3_close(db);
    //cout << "DTH tables created.\n";

    createUserTables();
    return true;
}

bool SqlReader::readFile(map<int, Languages*>& languageMap)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
    {
        cerr << "Cannot open database: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    const char* langSQL = "SELECT languageId, languageName FROM language;";
    if (sqlite3_prepare_v2(db, langSQL, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char* txt = sqlite3_column_text(stmt, 1);
            string name = txt ? reinterpret_cast<const char*>(txt) : "";
            languageMap[id] = new Languages(id, name);
        }
        sqlite3_finalize(stmt);
    }

    for (auto& [id, lang] : languageMap)
        loadChannelsAndPrograms(db, lang);

    sqlite3_close(db);
    return true;
}

void SqlReader::loadChannelsAndPrograms(sqlite3* db, Languages* lang)
{
    sqlite3_stmt* stmt;
    int languageId = lang->getLanguageId();

    const char* sql =
        "SELECT c.channelId, c.channelName, c.price, "
        "p.programId, p.programTitle, p.startTime, p.endTime "
        "FROM channels c LEFT JOIN programs p "
        "ON c.channelId = p.channelId WHERE c.languageId = ? "
        "ORDER BY c.channelId;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, languageId);
        int lastChannelId = -1;
        Channels* currentChannel = nullptr;

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int channelId = sqlite3_column_int(stmt, 0);
            const unsigned char* cn = sqlite3_column_text(stmt, 1);
            string channelName = cn ? reinterpret_cast<const char*>(cn) : "";
            double price = sqlite3_column_double(stmt, 2);

            if (channelId != lastChannelId)
            {
                lang->addChannel(channelId, channelName, price);
                currentChannel = lang->getChannelMap()[channelId];
                lastChannelId = channelId;
            }

            if (sqlite3_column_type(stmt, 3) != SQLITE_NULL)
            {
                int progId = sqlite3_column_int(stmt, 3);
                const unsigned char* pt = sqlite3_column_text(stmt, 4);
                const unsigned char* st = sqlite3_column_text(stmt, 5);
                const unsigned char* et = sqlite3_column_text(stmt, 6);
                string progTitle = pt ? reinterpret_cast<const char*>(pt) : "";
                string start = st ? reinterpret_cast<const char*>(st) : "";
                string end = et ? reinterpret_cast<const char*>(et) : "";
                if (currentChannel)
                    currentChannel->addProgram(progId, progTitle, start, end);
            }
        }
        sqlite3_finalize(stmt);
    }
}

bool SqlReader::insertLanguage(int languageId, const string& languageName)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO language (languageId, languageName) VALUES (?, ?);";

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, languageId);
        sqlite3_bind_text(stmt, 2, languageName.c_str(), -1, SQLITE_STATIC);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::updateLanguage(int languageId, const string& newName)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE language SET languageName = ? WHERE languageId = ?;";

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;
    bool success = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, newName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, languageId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::deleteLanguage(int languageId)
{
    sqlite3* db;
    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    sqlite3_stmt* stmt;
    const char* deletePrograms =
        "DELETE FROM programs WHERE channelId IN (SELECT channelId FROM channels WHERE languageId = ?);";
    sqlite3_prepare_v2(db, deletePrograms, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, languageId);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    const char* deleteChannels = "DELETE FROM channels WHERE languageId = ?;";
    sqlite3_prepare_v2(db, deleteChannels, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, languageId);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    const char* deleteLang = "DELETE FROM language WHERE languageId = ?;";
    sqlite3_prepare_v2(db, deleteLang, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, languageId);
    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}


bool SqlReader::insertChannel(int channelId, const string& channelName, const double& price, int languageId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO channels (channelId, channelName, price, languageId) VALUES (?, ?, ?, ?);";
    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;
    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, channelId);
        sqlite3_bind_text(stmt, 2, channelName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 3, price);
        sqlite3_bind_int(stmt, 4, languageId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::updateChannel(int channelId, const string& newChannelName, const double& newPrice, int languageId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql =
        "UPDATE channels SET channelName = ?, price = ?, languageId = ? WHERE channelId = ?;";
    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, newChannelName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 2, newPrice);
        sqlite3_bind_int(stmt, 3, languageId);
        sqlite3_bind_int(stmt, 4, channelId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::deleteChannel(int channelId)
{
    sqlite3* db;
    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    sqlite3_stmt* stmt;
    const char* deletePrograms = "DELETE FROM programs WHERE channelId = ?;";
    sqlite3_prepare_v2(db, deletePrograms, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, channelId);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    const char* deleteChannel = "DELETE FROM channels WHERE channelId = ?;";
    sqlite3_prepare_v2(db, deleteChannel, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, channelId);
    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return success;
}

bool SqlReader::insertProgram(int programId, const string& programTitle, const string& startTime,
                              const string& endTime, int channelId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql =
        "INSERT INTO programs (programId, programTitle, startTime, endTime, channelId) VALUES (?, ?, ?, ?, ?);";
    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;

    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, programId);
        sqlite3_bind_text(stmt, 2, programTitle.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, startTime.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, endTime.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 5, channelId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::updateProgram(int programId, const string& newProgramTitle, const string& newStartTime, const string& newEndTime)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql =
        "UPDATE programs SET programTitle = ?, startTime = ?, endTime = ? WHERE programId = ?;";
    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;

    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, newProgramTitle.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, newStartTime.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, newEndTime.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, programId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::deleteProgram(int programId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM programs WHERE programId = ?;";
    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;
    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, programId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::insertPackage(int packageId, const string& name, double price)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO packages (packageId, packageName, totalPrice) VALUES (?, ?, ?);";
    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;

    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, packageId);
        sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_double(stmt, 3, price);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::insertPackageChannel(int packageId, int channelId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO package_channels (packageId, channelId) VALUES (?, ?);";
    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;

    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, packageId);
        sqlite3_bind_int(stmt, 2, channelId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return success;
}

bool SqlReader::deletePackage(int packageId)
{
    sqlite3* db;
    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;
    sqlite3_stmt* stmt;

    const char* sql1 = "DELETE FROM package_channels WHERE packageId = ?;";
    sqlite3_prepare_v2(db, sql1, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, packageId);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    const char* sql2 = "DELETE FROM packages WHERE packageId = ?;";
    sqlite3_prepare_v2(db, sql2, -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, packageId);
    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return success;
}

bool SqlReader::readPackages(map<int, Package*>& packageMap, map<int, Languages*>& languageMap)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;

    const char* sql = "SELECT packageId, packageName, totalPrice FROM packages;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char* pn = sqlite3_column_text(stmt, 1);
            string name = pn ? reinterpret_cast<const char*>(pn) : "";
            double price = sqlite3_column_double(stmt, 2);
            packageMap[id] = new Package(id, name);
            packageMap[id]->setTotalPrice(price);
        }
        sqlite3_finalize(stmt);
    }

    const char* sql2 = "SELECT packageId, channelId FROM package_channels;";
    if (sqlite3_prepare_v2(db, sql2, -1, &stmt, nullptr) == SQLITE_OK)
    {
        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int pkgId = sqlite3_column_int(stmt, 0);
            int chId = sqlite3_column_int(stmt, 1);

            for (auto& langPair : languageMap)
            {
                auto& chMap = langPair.second->getChannelMap();
                if (chMap.find(chId) != chMap.end())
                {
                    if (packageMap.find(pkgId) != packageMap.end())
                        packageMap[pkgId]->addChannel(chMap[chId]);
                }
            }
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return true;
}

// ---- New functions ----

bool SqlReader::updatePackage(int packageId, const string& newName)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE packages SET packageName = ? WHERE packageId = ?;";

    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;
    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, newName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, packageId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::removePackageChannel(int packageId, int channelId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "DELETE FROM package_channels WHERE packageId = ? AND channelId = ?;";

    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;
    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, packageId);
        sqlite3_bind_int(stmt, 2, channelId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::updatePackagePrice(int packageId, double newPrice)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "UPDATE packages SET totalPrice = ? WHERE packageId = ?;";

    if (sqlite3_open("dth.db", &db) != SQLITE_OK) return false;
    bool success = false;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_double(stmt, 1, newPrice);
        sqlite3_bind_int(stmt, 2, packageId);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }
    sqlite3_close(db);
    return success;
}

bool SqlReader::createUserTables()
{
    sqlite3* db;
    char* errMsg = nullptr;
    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    const char* adminSQL =
        "CREATE TABLE IF NOT EXISTS Admins (id INTEGER PRIMARY KEY, name TEXT, password TEXT, phone TEXT);";

    const char* customerSQL =
        "CREATE TABLE IF NOT EXISTS Customers (id INTEGER PRIMARY KEY, name TEXT, password TEXT, phone TEXT);";

    const char* customerPackageSQL =
        "CREATE TABLE IF NOT EXISTS CustomerPackages ( "
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "customerId INTEGER, "
        "packageId INTEGER, "
        "transactionRef TEXT, "
        "paymentMethod TEXT, "
        "FOREIGN KEY(customerId) REFERENCES Customers(id), "
        "FOREIGN KEY(packageId) REFERENCES packages(packageId));";

    sqlite3_exec(db, adminSQL, nullptr, nullptr, &errMsg);
    sqlite3_exec(db, customerSQL, nullptr, nullptr, &errMsg);
    sqlite3_exec(db, customerPackageSQL, nullptr, nullptr, &errMsg);

    const char* defaultAdminSQL =
        "INSERT OR IGNORE INTO Admins (id, name, password, phone) "
        "VALUES (1, 'SuperAdmin', 'admin123', '9999999999');";

    sqlite3_exec(db, defaultAdminSQL, nullptr, nullptr, &errMsg);

    sqlite3_close(db);
    return true;
}


bool SqlReader::insertUser(const string& type, int id, const string& name, const string& password, const string& phone)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    string t = type;
    for (char &c : t) c = tolower(c);

    string table = (t == "admin") ? "Admins" : "Customers";
    bool success = false;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    string sql = "INSERT INTO " + table + " (id, name, password, phone) VALUES (?, ?, ?, ?);";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, phone.c_str(), -1, SQLITE_STATIC);
        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return success;
}

bool SqlReader::verifyUser(const string& type, int id, const string& password)
{
    sqlite3* db;
    sqlite3_stmt* stmt;

    string t = type;
    for (char &c : t) c = tolower(c);

    string table = (t == "admin") ? "Admins" : "Customers";
    bool verified = false;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    string sql = "SELECT password FROM " + table + " WHERE id = ?;";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, id);
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            const unsigned char* sp = sqlite3_column_text(stmt, 0);
            string storedPass = sp ? reinterpret_cast<const char*>(sp) : "";
            verified = (storedPass == password);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return verified;
}

bool SqlReader::updateUser(const string& type, int id, const string& name, const string& phone, const string& password)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    string t = type;
    for (char &c : t) c = tolower(c);

    string table = (t == "admin") ? "Admins" : "Customers";
    bool success = false;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    string sql = "UPDATE " + table + " SET name = ?, phone = ?, password = ? WHERE id = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, phone.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, password.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, id);

        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return success;
}

bool SqlReader::userExists(const string& type, const string& phone)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    string t = type;
    for (char &c : t) c = tolower(c);

    string table = (t == "admin") ? "Admins" : "Customers";
    bool exists = false;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    string sql = "SELECT COUNT(*) FROM " + table + " WHERE phone = ?;";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_text(stmt, 1, phone.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int count = sqlite3_column_int(stmt, 0);
            exists = (count > 0);
        }

        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return exists;
}

bool SqlReader::userExists(const string& type, int id)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    string t = type;
    for (char &c : t) c = tolower(c);

    string table = (t == "admin") ? "Admins" : "Customers";
    bool exists = false;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    string sql = "SELECT COUNT(*) FROM " + table + " WHERE id = ?;";

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, id);
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            int count = sqlite3_column_int(stmt, 0);
            exists = (count > 0);
        }
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return exists;
}

bool SqlReader::getUser(const string& type, int id)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    string t = type;
    for (char &c : t) c = tolower(c);

    string table = (t == "admin") ? "Admins" : "Customers";
    bool found = false;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    string sql = "SELECT * FROM " + table + " WHERE id = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, id);
        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            found = true;
            cout << "\n===== " << (type == "admin" ? "Admin" : "Customer") << " Details =====\n";
            cout << "ID: " << sqlite3_column_int(stmt, 0) << "\n";
            cout << "Name: "
                 << (sqlite3_column_text(stmt, 1) ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) : "")
                 << "\n";
            cout << "Phone: "
                 << (sqlite3_column_text(stmt, 3) ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)) : "")
                 << "\n";
        }
        sqlite3_finalize(stmt);
    }

    if (!found)
        cout << "User not found.\n";

    sqlite3_close(db);
    return found;
}



bool SqlReader::getUser(const string& type, int id,
                        int& outId,
                        string& outName,
                        string& outPassword,
                        string& outPhone)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    string t = type;
    for (char &c : t) c = tolower(c);

    string table = (t == "admin") ? "Admins" : "Customers";
    bool found = false;

    outId = -1;
    outName = "";
    outPassword = "";
    outPhone = "";

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    string sql = "SELECT * FROM " + table + " WHERE id = ?;";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_ROW)
        {
            found = true;

            outId = sqlite3_column_int(stmt, 0);
            outName = (const char*)sqlite3_column_text(stmt, 1);
            outPassword = (const char*)sqlite3_column_text(stmt, 2);
            outPhone = (const char*)sqlite3_column_text(stmt, 3);

            cout << "\n===== " << (type == "admin" ? "Admin" : "Customer") << " Details =====\n";
            cout << "ID: " << outId << "\n";
            cout << "Name: " << outName << "\n";
            cout << "Phone: " << outPhone << "\n";
        }

        sqlite3_finalize(stmt);
    }

    if (!found)
        cout << "User not found.\n";

    sqlite3_close(db);
    return found;
}


bool SqlReader::insertCustomerPackage(int customerId, int packageId, const string& transactionRef, const string& paymentMethod)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    const char* sql = "INSERT INTO CustomerPackages (customerId, packageId, transactionRef, paymentMethod) VALUES (?, ?, ?, ?);";

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    bool success = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, customerId);
        sqlite3_bind_int(stmt, 2, packageId);
        sqlite3_bind_text(stmt, 3, transactionRef.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, paymentMethod.c_str(), -1, SQLITE_STATIC);

        success = (sqlite3_step(stmt) == SQLITE_DONE);
        sqlite3_finalize(stmt);
    }

    sqlite3_close(db);
    return success;
}

bool SqlReader::getCustomerPackages(int customerId)
{
    sqlite3* db;
    sqlite3_stmt* stmt;
    bool hasData = false;

    if (sqlite3_open("dth.db", &db) != SQLITE_OK)
        return false;

    const char* sql =
        "SELECT p.packageId, p.packageName, p.totalPrice, c.transactionRef, c.paymentMethod "
        "FROM CustomerPackages c "
        "JOIN packages p ON c.packageId = p.packageId "
        "WHERE c.customerId = ?;";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
    {
        sqlite3_bind_int(stmt, 1, customerId);
        cout << "\n===== Subscribed Packages =====\n";

        while (sqlite3_step(stmt) == SQLITE_ROW)
        {
            hasData = true;
            cout << "Package ID: " << sqlite3_column_int(stmt, 0)
                 << ", Name: " << (sqlite3_column_text(stmt, 1) ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) : "")
                 << ", Price: " << sqlite3_column_double(stmt, 2)
                 << "\nTransaction: " << (sqlite3_column_text(stmt, 3) ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)) : "")
                 << ", Method: " << (sqlite3_column_text(stmt, 4) ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)) : "") << "\n\n";
        }
        sqlite3_finalize(stmt);
    }

    if (!hasData)
        cout << "You have not subscribed to any packages yet.\n";

    sqlite3_close(db);
    return true;
}
