#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

// class MyVector
// {
//     vector<int> data;

// public:
//     void add(int value)
//     {
//         data.push_back(value);
//     }

//     void display()
//     {
//         for(int x : data)
//             cout << x << " ";
//         //cout << endl;
//     }

//     void update(int newValue,int index)
//     {
//         if (index >= 0 && index < data.size())
//             data[index] = newValue;
//     }

//     void remove(int index)
//     {
//         if(index >=0 &&  index<data.size())
//             data.erase(data.begin() + index);
//     }
// };

class MyMap
{
    map<int,string> data;

public:
    void add(int id, string &name)
    {
      data[id] = name;
    }

    void display()
    {
        for (auto &p : data)
        {
            cout << p.first << "->" << p.second << endl;
        }
    }

    void update(int id, string &newName)
    {
        if(data.find(id) != data.end())
            data[id] = newName;
    }

    void remove(int id)
    {
        data.erase(id);
    }
};

class ListCRUD
{
    list<int> data;

public:
    void add(int value)
    {
        data.push_back(value);
    }

    void display()
    {
        for (int x : data)
            cout << x << " ";
        cout << endl;
    }

    void update(int oldValue, int newValue)
    {
        for (int &x : data)
        {
            if (x == oldValue)
            {
                x = newValue;
                return;
            }
        }
    }

    void remove(int value)
    {
        data.remove(value);
    }
};

void func(int &&value)
{
    int &temp = value;
}

int main()
{
    // MyVector v;

    // v.add(10);
    // v.add(20);

    // v.display();

    // v.update(30,1);

    // v.display();

    // v.remove(2);

    // v.display();

    int a = 20;
    func(20);
    //int &b = a;




    return 0;
}
