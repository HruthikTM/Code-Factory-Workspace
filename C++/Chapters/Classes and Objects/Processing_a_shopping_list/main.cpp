#include <iostream>

using namespace std;

const int m = 50;

class Items
{
    int itemCode[m];
    float itemPrice[m];
    int count;

public:
    void CNT(void)
    {
        count = 0;
    }
    void getItems(void);
    void displaySum(void);
    void remove(void);
    void displayItems(void);
};


void Items :: getItems(void)
{
    cout << "Enter item code: ";
    cin >> itemCode[count];
    cout << "Enter item cost: ";
    cin >> itemPrice[count];
    count++;
}

void Items :: displaySum(void)
{
    float sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum = sum + itemPrice[i];
        cout << "\nTotal value: " << sum << "\n";
    }
}

void Items :: remove(void)
{
    int a;
    cout << "Enter item code: ";
    cin >> a;

    for (int i = 0; i < count; i++)
    {
        if(itemCode[i] == a)
            itemPrice[i] = 0;
    }
}

void Items :: displayItems(void)
{
    cout << "\nCode Price\n";

    for (int i = 0; i < count; i++)
    {
        cout << "\n" << itemCode[i];
        cout << "\n" << itemPrice[i];
    }

    cout << "\n";
}

int main()
{

    Items order;
    order.CNT();
    int choice;

    do
    {
        cout << "\n1 : Add an item";
        cout << "\n2 : Display total value";
        cout << "\n3 : Delete an item";
        cout << "\n4 : Display all items";
        cout << "\n5 : Quit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            order.getItems();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displayItems();
            break;
        case 5:
            break;
        default:
            cout << "\nInvalid Choice... try Again\n ";
        }
    }while(choice != 5);

    return 0;
}
