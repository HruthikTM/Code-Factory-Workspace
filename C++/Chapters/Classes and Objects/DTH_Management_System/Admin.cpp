#include "Admin.h"
#include "MainDataModel.h"
#include <iostream>

Admin::Admin()
{

}

int Admin::getValidatedInt()
{
    int value;
    while (true)
    {
        cin >> value;

        if (!cin.fail())
        {
            cin.ignore(1000,'\n');
            return value;
        }
        else
        {
            cin.clear();
            while(getchar() != '\n');
            cout << "Invalid input.\n";
        }
    }
    return value;
}

string Admin::getValidatedName()
{
    string input;
    while (true)
    {
        getline(cin,input);
        cout << "name 1: " << input << endl;

        if (input.empty())
        {
            cout << "Name cannot be empty. Enter again: ";
            continue;
        }

        bool valid = true;
        for (char c : input)
        {
            if (!isalpha(c) && c != ' ')
            {
                valid = false;
                break;
            }
        }
        cout << "name : " << input << endl;

        if (valid)
            return input;

        cout << "Invalid name! Enter alphabets only: ";
    }
}

string Admin::getValidatedChannelName()
{
    string input;
    while (true)
    {
        getline(cin, input);

        if (input.empty())
        {
            cout << "Channel name cannot be empty. Enter again: ";
            continue;
        }

        bool valid = true;
        for (char c : input)
        {
            if (!isalnum(c) && c != ' ')
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return input;

        cout << "Invalid channel name! Only letters, digits & spaces allowed: ";
    }
}



bool Admin::isValidTime(const string &time)
{
    if (time.empty()) return false;
    if (time.size() != 5 || time[2] != ':') return false;


    if (!isdigit(time[0]) || !isdigit(time[1]) ||
        !isdigit(time[3]) || !isdigit(time[4]))
        return false;

    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));

    return (h >= 0 && h < 24 && m >= 0 && m < 60);
}

double Admin::getValidatedPrice()
{
    double price;
    while (true)
    {
        cin >> price;

        if (!cin.fail() && price > 0)
        {
            cin.ignore(1000, '\n');
            return price;
        }

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid price! Enter a number greater than 0: ";
    }
}

void Admin::adminMenu()
{
    MainDataModel* m_model = MainDataModel::getInstance();


    while (true)
    {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Create Language\n";
        cout << "2. Delete Language\n";
        cout << "3. Display Languages\n";
        cout << "4. Create Channel\n";
        cout << "5. Edit Channel\n";
        cout << "6. Delete Channel\n";
        cout << "7. Create Program\n";
        cout << "8. Edit Program\n";
        cout << "9. Delete Program\n";
        cout << "10. Create Package\n";
        cout << "11. Edit Package\n";
        cout << "12. Delete Package\n";
        cout << "13. Display Packages\n";
        cout << "14. Logout\n";
        cout << "Choice: ";

        int ch = getValidatedInt();
        if (ch == 14) return;

        int lid, cid, pid, pkgId;
        string name, start, end;
        double price;

        switch (ch)
        {
        case CREATE_LANGUAGE:
            cout << "Enter Language ID: ";
            lid = getValidatedInt();

            cout << "Enter Language Name: ";
            name = getValidatedName();

            m_model->createLanguage(lid, name);
            break;

        case DELETE_LANGUAGE:
            cout << "Enter Language ID: ";
            lid = getValidatedInt();
            m_model->deleteLanguage(lid);
            break;

        case DISPLAY_LANGUAGES:
            m_model->displayLanguages();
            break;

        case CREATE_CHANNEL:
            cout << "Language ID: ";
            lid = getValidatedInt();
            cout << "Channel ID: ";
            cid = getValidatedInt();

            cout << "Channel Name: ";
            name = getValidatedChannelName();

            cout << "Price: ";
            price = getValidatedPrice();

            m_model->createChannel(lid, cid, name, price);
            break;

        case EDIT_CHANNEL:
            cout << "Language ID: ";
            lid = getValidatedInt();
            cout << "Channel ID: ";
            cid = getValidatedInt();

            cout << "New Channel Name: ";
            name = getValidatedChannelName();

            cout << "New Price: ";
            price = getValidatedPrice();

            m_model->updateChannel(lid, cid, name, price);
            break;

        case DELETE_CHANNEL:
            cout << "Language ID: ";
            lid = getValidatedInt();
            cout << "Channel ID: ";
            cid = getValidatedInt();
            m_model->deleteChannel(lid, cid);
            break;

        case CREATE_PROGRAM:
            cout << "Language ID: ";
            lid = getValidatedInt();
            cout << "Channel ID: ";
            cid = getValidatedInt();
            cout << "Program ID: ";
            pid = getValidatedInt();

            cin.ignore();
            cout << "Program Name: ";
            name = getValidatedChannelName();

            do
            {
                cout << "Start Time (HH:MM): ";
                getline(cin, start);
            } while (!isValidTime(start));

            do
            {
                cout << "End Time (HH:MM): ";
                getline(cin, end);
            } while (!isValidTime(end));

            m_model->createProgram(lid, cid, pid, name, start, end);
            break;

        case EDIT_PROGRAM:
            cout << "Language ID: ";
            lid = getValidatedInt();
            cout << "Channel ID: ";
            cid = getValidatedInt();
            cout << "Program ID: ";
            pid = getValidatedInt();

            cin.ignore();
            cout << "New Program Name: ";
            name = getValidatedChannelName();

            do
            {
                cout << "New Start Time (HH:MM): ";
                getline(cin, start);
            } while (!isValidTime(start));

            do
            {
                cout << "New End Time (HH:MM): ";
                getline(cin, end);
            } while (!isValidTime(end));

            m_model->updateProgram(lid, cid, pid, name, start, end);
            break;

        case DELETE_PROGRAM:
            cout << "Language ID: ";
            lid = getValidatedInt();
            cout << "Channel ID: ";
            cid = getValidatedInt();
            cout << "Program ID: ";
            pid = getValidatedInt();
            m_model->deleteProgram(lid, cid, pid);
            break;

        case CREATE_PACKAGE:
            m_model->createPackage();
            break;

        case EDIT_PACKAGE:
            cout << "Enter Package ID: ";
            pkgId = getValidatedInt();
            m_model->editPackage(pkgId);
            break;

        case DELETE_PACKAGE:
            cout << "Enter Package ID: ";
            pkgId = getValidatedInt();
            m_model->deletePackage(pkgId);
            break;

        case DISPLAY_PACKAGES:
            m_model->displayPackages();
            break;

        case LOGOUT:
            cout << "Logging out...\n";
            return;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
