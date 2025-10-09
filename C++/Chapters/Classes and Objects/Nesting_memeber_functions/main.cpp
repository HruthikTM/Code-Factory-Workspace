#include <iostream>
#include <string>

using namespace std;

class Binary
{
    string s;

public:
    void read(void)
    {
        cout << "Enter a binary number: ";
        cin >> s;
    }

    void chk_bin(void)
    {
        for(int i=0; i<s.length(); i++)
        {
            if(s.at(i)!='0' && s.at(i)!='1')
            {
                cout << "\nIncorrect binary number format...";
                exit(0);
            }
        }
    }

    void ones(void)
    {
        chk_bin();
        for (int i = 0; i < s.length(); i++)
        {
            if(s.at(i) == '0')
                s.at(i) = '1';
            else
                s.at(i) = '0';
        }
    }

    void displayones(void)
    {
        ones();
        cout << "the one's complement of above binary number is: "<<s;
    }

};

int main()
{
    Binary b;
    b.read();
    b.displayones();
    return 0;
}
