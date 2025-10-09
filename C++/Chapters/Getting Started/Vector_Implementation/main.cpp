#include <iostream>
using namespace std;

int* resizeArray(int* oldArray, int oldSize, int newSize)
{
    int* newArray = new int[newSize];

    for (int i = 0; i < oldSize; ++i)
    {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray;

    return newArray;
}

int main()
{
    int capacity;
    cout << "Enter initial size of array: ";
    cin >> capacity;

    int* arr = new int[capacity];
    int size = 0;
    char choice;
    do
    {
        int value;
        cout << "Enter element " << (size + 1) << ": ";
        cin >> value;


        if (size >= capacity)
        {
            int newCapacity = capacity * 2;
            arr = resizeArray(arr, capacity, newCapacity);
            capacity = newCapacity;
            cout << "Array resized to capacity: " << capacity << endl;
        }

        arr[size++] = value;

        cout << "Do you want to enter another element? (y/n): ";
        cin >> choice;

    }while (choice == 'y' || choice == 'Y');

    cout << "Final array elements: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
