#include "heap.h"

int main()
{
    string input;
    getline(cin, input);
    Heap my_heap;
    my_heap.buildHeap(input);
    my_heap.printHeap();
    return 0;
}