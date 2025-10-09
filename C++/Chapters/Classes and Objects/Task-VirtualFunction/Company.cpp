#include "Company.h"
#include "Csv_Reader.h"
#include "Txt_Reader.h"
#include "Sql_Reader.h"
#include <iomanip>

enum  Operation{
    Fetch_Data = 1,
    Display_Data,
    EXIT
};

enum  FetchFile{
    Fetch_CSV = 1,
    Fetch_Text,
    Fetch_SQL,
    Main_Menu
};

enum  DisplayFile{
    Display_CSV = 1,
    Display_Text,
    Display_SQL,
    Mainmenu
};

Company::Company()
{
    cout << "Company Constructor" << endl;
}

Company::~Company()
{
    cout << "Company Destructor" << endl;
}

void Company::display(const list<EmployeeDetails*>& lst)
{
    if (lst.empty())
    {
        cout << "No data available" << endl;
        return;
    }

    cout << left << setw(5)  << "ID" << left << setw(20) << "Name" << "Designation" << endl;;

    for (auto e : lst)
        cout << left << setw(5)  << e->getEmployeeId() << left << setw(20) << e->getEmployeeName() << e->getEmployeeDesg() << '\n';
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
            bool fetchMenu = true;
            while (fetchMenu)
            {
                cout << "\nChoose the File Type to Fetch data\n"
                     << "1. CSV File\n"
                     << "2. Text File\n"
                     << "3. SQL File\n"
                     << "4. Back to Main Menu\n";

                int fchoice;
                cin >> fchoice;

                switch (fchoice)
                {
                case Fetch_CSV:
                {
                    FileReader *file = new Csv_Reader;
                    file->readFile(csvList);
                    delete file;
                    break;
                }
                case Fetch_Text:
                {
                    FileReader *file = new Txt_Reader;
                    file->readFile(txtList);
                    delete file;
                    break;
                }
                case Fetch_SQL:
                {
                    FileReader *file = new Sql_Reader;
                    file->readFile(sqlList);
                    delete file;
                    break;
                }
                case Mainmenu:
                    fetchMenu = false;
                    break;
                default:
                    cout << "Invalid Fetch Choice.." << endl;
                    break;
                }
            }
            break;
        }

        case Display_Data:
        {
            bool displayMenu = true;
            while (displayMenu)
            {
                cout << "\nChoose the File Type to Display Data\n"
                     << "1. CSV File\n"
                     << "2. Text File\n"
                     << "3. SQL File\n"
                     << "4. Back to Main Menu\n";

                int dChoice;
                cin >> dChoice;

                switch (dChoice)
                {
                case Display_CSV:
                    display(csvList);
                    break;
                case Display_Text:
                    display(txtList);
                    break;
                case Display_SQL:
                    display(sqlList);
                    break;
                case Mainmenu:
                    displayMenu = false;
                    break;
                default:
                    cout << "Invalid Display Choice" << endl;
                    break;
                }
            }
            break;
        }

        case EXIT:
            cout << "Exiting program.." << endl;
            running = false;
            break;

        default:
            cout << "Invalid Choice!." << endl;
            break;
        }
    }
}
