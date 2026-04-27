#include <iostream>

using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Linkedlist
{
private:
    Node *head;

public:

    Linkedlist()
    {
        head = nullptr;
    }

    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);

        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if(head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtPosition(int value, int position)
    {
        Node *newNode = new Node(value);

        if(position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        int currentPos = 1;

        while(temp != nullptr && currentPos < position-1)
        {
            temp = temp->next;
            currentPos++;
        }

        if(temp == nullptr)
        {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteHead() //to delete by value, send value agrs to deletefunction
    {
        if(head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        //check if head contains any data i.e head->data = value
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteLast()
    {
        if(head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;

        //find second last node
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        //temp is now second last node
        Node *last = temp->next;
        temp->next = nullptr;
        delete last;
    }

    void deleAtPosition(int position)
    {
        if(head == nullptr)
        {
            cout << "list is empty" << endl;
            return;
        }

        if(position == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;
        int currentPos = 1;

        while(temp->next != nullptr && currentPos < position-1)
        {
            temp = temp->next;
            currentPos++;
        }

        if(temp->next == nullptr || temp == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node *nodetoDelete = temp->next;
        temp->next = temp->next->next;

        delete nodetoDelete;
    }

    void display()
    {
        Node *temp = head;
        while(temp!=nullptr)
        {
            cout << temp->data << "->" ;
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

};

int main()
{
    // Linkedlist lst;

    // lst.insertAtHead(10);
    // lst.insertAtHead(20);
    // lst.insertAtHead(30);

    // lst.display();
    // lst.insertAtHead(40);
    // lst.display();

    // lst.insertAtEnd(50);
    // lst.display();

    // lst.insertAtPosition(80,3);

    // lst.display();

    // lst.insertAtPosition(99,9);
    // lst.display();

    // lst.deleteHead();
    // lst.display();

    // lst.deleteLast();
    // lst.display();

    // lst.deleAtPosition(5);
    // lst.display();

    double a= 10.00001;
    cout << a << endl;
    return 0;
}
