#include <iostream>
#include "MathOperation.h"

using namespace std;

int main()
{
    int x, y, x2, y2, choice;
    cout << "Enter Numbers for o1 : ";
    cin >> x >> y;

    cout << "Enter Numbers for o2 : ";
    cin >> x2 >> y2;

    MathOperation o1(x, y);
    MathOperation o2(x2, y2);
    MathOperation o3;

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Addition (+)\n";
        cout << "2. Subtraction (-)\n";
        cout << "3. Multiplication (*)\n";
        cout << "4. Division (/)\n";
        cout << "5. Less Than (<)\n";
        cout << "6. Greater Than (>)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            o3 = o1 + o2;
            cout << "\nAddition Operation:\n";
            o3.display();
            break;

        case 2:
            o3 = o1 - o2;
            cout << "\nSubtraction Operation:\n";
            o3.display();
            break;

        case 3:
            o3 = o1 * o2;
            cout << "\nMultiplication Operation:\n";
            o3.display();
            break;

        case 4:
            o3 = o1 / o2;
            cout << "\nDivision Operation:\n";
            o3.display();
            break;

        case 5:
            if (o1 < o2)
                cout << "\no1 is LESS than o2\n";
            else
                cout << "\no1 is NOT less than o2\n";
            break;

        case 6:
            if (o1 > o2)
                cout << "\no1 is GREATER than o2\n";
            else
                cout << "\no1 is NOT greater than o2\n";
            break;

        case 7:
            cout << "Exiting program.." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
