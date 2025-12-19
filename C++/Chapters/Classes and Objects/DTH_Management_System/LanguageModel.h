#ifndef LANGUAGEMODEL_H
#define LANGUAGEMODEL_H

#include <map>
#include <string>
#include <iostream>

#include "Language.h"
#include "SqlReader.h"

using namespace std;

class LanguageModel
{
public:
    LanguageModel();

    void createLanguage(int id, const string& name);
    void deleteLanguage(int id);
    void displayLanguages();

    void createChannel(int langId, int chId, const string& name, double price);
    void updateChannel(int langId, int chId, const string& name, double price);
    void deleteChannel(int langId, int chId);
    void displayChannels(int langId);

    void createProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end);

    void updateProgram(int langId, int chId, int prgId, const string& name, const string& start, const string& end);

    void deleteProgram(int langId, int chId, int prgId);
    void displayPrograms(int langId, int chId);

    map<int, Languages*>& getLanguageMap();

private:
    map<int, Languages*> m_languageMap;
    SqlReader* m_reader;

    int getValidatedInt();
};

#endif
