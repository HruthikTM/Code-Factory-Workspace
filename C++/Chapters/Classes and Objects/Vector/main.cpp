#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> &m_vector)
{
    for(int i=0; i<m_vector.size(); i++)
        cout << m_vector[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int>* m_vector = new vector<int>();
    cout << "Initial size : "<< m_vector->size() << endl;
    cout << "size : "<< sizeof(m_vector) << endl;


    int x;
    cout << "Enter five integer values : " << endl;

    for(int i = 0; i < 5; i++)
    {
        cin>>x;
        m_vector->push_back(x);
    }

    cout << "Size after adding 5 elements : "<< m_vector->size() << endl;

    cout<<"Displaying elements" << endl;
    display(*m_vector);

    m_vector->push_back(8.9);
    cout << "Size after extra/new elements : "<< m_vector->size() << endl;

    vector<int> :: iterator itr = m_vector->begin();
    itr = itr + 3;
    m_vector->insert(itr,1,9);

    display(*m_vector);

    m_vector->erase(m_vector->begin() + 3, m_vector->begin() + 5);

    cout << "Contents after deletion" << endl;
    display(*m_vector);

    cout << "size : "<< m_vector->size() << endl;
    cout << "size : "<< sizeof(m_vector) << endl;

    // m_vector.erase(itr + 2); // though it is showing the o/p it is undefined behaviour
    // display(m_vector);

    delete m_vector;

    return 0;
}
