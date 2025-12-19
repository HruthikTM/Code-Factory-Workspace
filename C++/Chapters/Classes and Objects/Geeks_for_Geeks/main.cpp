#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input = "Geeks for Geeks";
    string word = "";

    for(int i=0;i<input.length();i++)
    {
        char ch = input[i];

        if(ch != ' ')
        {
            word = word + ch;
        }
        else
        {
            cout << word << endl;
            word = "";
        }
    }

    if(!word.empty())
        cout << word << endl;
    return 0;
}
