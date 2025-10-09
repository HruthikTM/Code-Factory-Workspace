#include "Company.h"
#include "FileReader.h"
#include "Csv_Reader.h"
#include "Txt_Reader.h"
#include "Sql_Reader.h"
#include <iomanip>

Company::Company()
{
    cout << "Company Constructor" << endl;
    m_fileMap = {{CSV, new Csv_Reader}, {TEXT, new Txt_Reader}, {SQL, new Sql_Reader}};
}

Company::~Company()
{
    cout << "Company Destructor" << endl;

    for (auto &pair : m_fileMap)
    {
        delete pair.second;
        pair.second = nullptr;
    }
}

void Company::display()
{
    while (true)
    {
        cout << "\nChoose the File Type to Display Data\n"
             << "1. CSV File\n"
             << "2. Text File\n"
             << "3. SQL File\n"
             << "4. Back to Main Menu\n";

        int dChoice;
        cin >> dChoice;

        if (dChoice == 4)
            break;

        //auto file = m_fileMap.find(static_cast<FileType>(dChoice));

        //pair<FileType, FileReader*> file = m_fileMap.find(static_cast<FileType>(dChoice));

        map<FileType, FileReader*>::iterator file = m_fileMap.find(static_cast<FileType>(dChoice));

        if (file != m_fileMap.end())
            file->second->displayFile();
        else
            cout << "Invalid choice.." <<endl;
    }
}


void Company::setupFile()
{
    bool running = true;
    while (running)
    {
        cout << "\nSelect the Operation\n"
             << "1. Fetch Data\n"
             << "2. Display Data\n"
             << "3. Exit\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case Fetch_Data:
        {
            while (true)
            {
                cout << "\nChoose the File Type to Fetch data\n"
                     << "1. CSV File\n"
                     << "2. Text File\n"
                     << "3. SQL File\n"
                     << "4. Back to Main Menu\n";

                int fChoice;
                cin >> fChoice;

                if (fChoice == 4)
                    break;

                // auto file = m_fileMap.find(static_cast<FileType>(fchoice));

                map<FileType, FileReader*>::iterator file = m_fileMap.find(static_cast<FileType>(fChoice));

                if (file != m_fileMap.end())
                    file->second->readFile();
                else
                    cout << "Invalid choice" << endl;
            }
            break;
        }

        case Display_Data:
            display();
            break;

        case EXIT:
            cout << "Exiting program.." << endl;
            running = false;
            break;

        default:
            cout << "Invalid Choice.." << endl;
            break;
        }
    }
}
