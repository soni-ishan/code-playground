#include "heap.h"

int main()
{
    string input;
    getline(cin, input);
    minHeap<int> my_heap;
    my_heap.buildHeap(input);
    my_heap.printHeap();
    cout << my_heap.findMax()<<endl;
    my_heap.deleteMin();
    my_heap.printHeap();
    return 0;
}