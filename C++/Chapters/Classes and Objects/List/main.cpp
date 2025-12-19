#include <iostream>
#include <list>

using namespace std;

void display(const list<int> &m_list)
{
    for (int x : m_list)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    list<int> m_list1;
    list<int> m_list2;
    int x;

    cout << "Enter 3 elements for list1:\n";
    for (int i = 0; i < 3; i++) {
        cin >> x;
        m_list1.push_back(x);
    }

    cout << "Enter 5 elements for list2:\n";
    for (int i = 0; i < 5; i++) {
        cin >> x;
        m_list2.push_back(x);
    }

    display(m_list1);
    display(m_list2);

    m_list1.push_back(100);
    m_list1.push_front(200);

    m_list2.pop_front();

    display(m_list1);
    display(m_list2);

    list<int> listA = m_list1;
    list<int> listB = m_list2;

    // Merge (must be sorted)
    m_list1.sort();
    m_list2.sort();
    m_list1.merge(m_list2);

    cout << "Merged m_list1:\n";
    display(m_list1);

    listA.sort();
    listB.sort();
    listA.merge(listB);

    cout << "Merged listA:\n";
    display(listA);

    listA.reverse();
    cout << "Reversed listA:\n";
    display(listA);

    return 0;
}
