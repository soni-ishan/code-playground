#include "heap.h"

int main()
{
    string input;
    cout << "Enter positive numbers for to build heap separatedby spaces: ";
    getline(cin, input);
    Heap my_heap;
    my_heap.buildHeap(input);
    cout << "Heap: " << endl;
    my_heap.printHeap();
    int choice = 0;
    do
    {
        cout << "What operation would you like to perform?" << endl;
        cout << "1. Insert element" << endl;
        cout << "2. deleteMin" << endl;
        cout << "3. deleteMax" << endl;
        cout << "4. findMin" << endl;
        cout << "5. findMax" << endl;
        cout << "6. Exit the program" << endl;
        cout << "Enter choice from 1 to 6: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int new_element;
            cout << "Enter a positive number to insert: " << endl;
            cin >> new_element;
            try
            {
                if (new_element > 0)
                {
                    my_heap.insertHeap(new_element);
                    cout << "Invalid element" << endl;
                }
            }
            catch (const invalid_argument &e)
            {
                cout << "Invalid element" << endl;
            }
            break;
        case 2:
            my_heap.deleteMin();
            my_heap.printHeap();
            break;
        case 3:
            my_heap.deleteMax();
            my_heap.printHeap();
            break;
        case 4:
            cout << "Min = " << my_heap.findMin() << endl;
            break;
        case 5:
            cout << "Max = " << my_heap.findMax() << endl;
            break;
        case 6:
            break;
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
    } while (choice != 6);
    return 0;
}