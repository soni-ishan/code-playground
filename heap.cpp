#include "heap.h"

bool Heap::isFull()
{
    return (curr_size == MAX_LENGTH);
}

void Heap::buildHeap(string input)
{
    curr_size = 0;
    vector<int> element_list = string_to_list(input);

    // first put all the input elements into the heap array
    for (int i = 0; i < element_list.size(); i++)
    {
        curr_size++;
        heap[curr_size] = element_list[i];
    }

    // run TrickleDown function to arrange the elements in a min max heap
    for (int i = curr_size / 2; i > 0; i--)
    {
        TrickleDown(i);
    }
}

bool Heap::getDescendentType(int index, int descendent_index)
{
    // assuming we know that element at descendent_index is either child or grandchild of element at index
    return (descendent_index <= 2 * index + 1);
    // if true then element is child
    // if false then element is grandchild
}

bool Heap::getLevelType(int index)
{
    int level = log2(index);
    return (level % 2 == 0);
    // true(1) for even(min) levels
    // false(0) for odd(max) levels
}

void Heap::TrickleDown(int index)
{
    // if index is on min level
    if (getLevelType(index))
    {
        TrickleDownMin(index);
    }
    // if index is on max level
    else
    {
        TrickleDownMax(index);
    }
}

int Heap::getSmallestDescendent(int index)
{
    // assume element at index has at least one child

    // get indexes of children
    int left_child_index = 2 * index;
    int right_child_index = 2 * index + 1;

    // get indexes of children of left child
    int left_left_child_index = 2 * left_child_index;
    int right_left_child_index = 2 * left_child_index + 1;

    // get indexes of children of right child
    int left_right_child_index = 2 * right_child_index;
    int right_right_child_index = 2 * right_child_index + 1;

    // initialize the smallest_descendent_index as the left_child_index
    int smallest_descendent_index = left_child_index;

    // check if element has two children
    if (right_child_index <= curr_size)
    {
        // get the smaller of the left and right children
        smallest_descendent_index = min(smallest_descendent_index, right_child_index);
        // check if the left child has any children
        // first check for one child
        if (left_left_child_index <= curr_size)
        {
            // if one child present, compare with smallest_descendent_index
            smallest_descendent_index = min(smallest_descendent_index, left_left_child_index);
            // check if the left child has a second child
            if (right_left_child_index <= curr_size)
            {
                // if second child present, compare with smallest_descent_index
                smallest_descendent_index = min(smallest_descendent_index, right_left_child_index);
                // check if the right child has one child
                if (left_right_child_index <= curr_size)
                {
                    // if one child present, compare with smallest_descendent_index
                    smallest_descendent_index = min(smallest_descendent_index, left_right_child_index);
                    // check if right child has a second child
                    if (right_right_child_index <= curr_size)
                    {
                        // if second child present, compare with smallest_descent_index
                        smallest_descendent_index = min(smallest_descendent_index, right_right_child_index);
                    }
                }
            }
            // if the left child has only one child
            // then the right child does not have any children
        }
        // if the left child does not have any children
        // then the right child also does not have any children
    }
    // if element at index has only left child and no right child
    // this means that element has no grandchildren
    // so left_child_index is the only descendent
    return smallest_descendent_index;
}

void Heap::TrickleDownMin(int index)
{
    // if element at index has children
    if (index <= curr_size / 2)
    {
        // get the index of the smallest of the children and grandchildren (if any)
        int smallest_descendent_index = getSmallestDescendent(index);
        // if smallest descendent is the grandchild of index element
        if (getDescendentType(index, smallest_descendent_index) == false)
        {
            if (heap[smallest_descendent_index] < heap[index])
            {
                swapElements(index, smallest_descendent_index);
                if (heap[smallest_descendent_index] > heap[smallest_descendent_index / 2])
                {
                    swapElements(smallest_descendent_index / 2, smallest_descendent_index);
                }
                TrickleDownMin(smallest_descendent_index);
            }
        }
        // if smallest element is the child of index element
        else
        {
            if (heap[smallest_descendent_index] < heap[index])
            {
                swapElements(index, smallest_descendent_index);
            }
        }
    }
}

int Heap::getLargestDescendent(int index)
{
    // assume element at index has at least one child

    // get indexes of children
    int left_child_index = 2 * index;
    int right_child_index = 2 * index + 1;

    // get indexes of children of left child
    int left_left_child_index = 2 * left_child_index;
    int right_left_child_index = 2 * left_child_index + 1;

    // get indexes of children of right child
    int left_right_child_index = 2 * right_child_index;
    int right_right_child_index = 2 * right_child_index + 1;

    // initialize the largest_descendent_index as the left_child_index
    int largest_descendent_index = left_child_index;

    // check if element has two children
    if (right_child_index <= curr_size)
    {
        // get the larger of the left and right children
        largest_descendent_index = max(largest_descendent_index, right_child_index);
        // check if the left child has any children
        // first check for one child
        if (left_left_child_index <= curr_size)
        {
            // if one child present, compare with largest_descendent_index
            largest_descendent_index = max(largest_descendent_index, left_left_child_index);
            // check if the left child has a second child
            if (right_left_child_index <= curr_size)
            {
                // if second child present, compare with largest_descent_index
                largest_descendent_index = max(largest_descendent_index, right_left_child_index);
                // check if the right child has one child
                if (left_right_child_index <= curr_size)
                {
                    // if one child present, compare with largest_descendent_index
                    largest_descendent_index = max(largest_descendent_index, left_right_child_index);
                    // check if right child has a second child
                    if (right_right_child_index <= curr_size)
                    {
                        // if second child present, compare with largest_descent_index
                        largest_descendent_index = max(largest_descendent_index, right_right_child_index);
                    }
                }
            }
            // if the left child has only one child
            // then the right child does not have any children
        }
        // if the left child does not have any children
        // then the right child also does not have any children
    }
    // if element at index has only left child and no right child
    // this means that element has no grandchildren
    // so left_child_index is the only descendent
    return largest_descendent_index;
}

void Heap::TrickleDownMax(int index)
{
    // if element at index has children
    if (index <= curr_size / 2)
    {
        // get the index of the largest of the children and grandchildren (if any)
        int largest_descendent_index = getLargestDescendent(index);
        // if largest descendent is the grandchild of index element
        if (getDescendentType(index, largest_descendent_index) == false)
        {
            if (heap[largest_descendent_index] > heap[index])
            {
                swapElements(index, largest_descendent_index);
                if (heap[largest_descendent_index] < heap[largest_descendent_index / 2])
                {
                    swapElements(largest_descendent_index / 2, largest_descendent_index);
                }
                TrickleDownMax(largest_descendent_index);
            }
        }
        // if largest descendent is the child of index element
        else
        {
            if (heap[largest_descendent_index] > heap[index])
            {
                swapElements(index, largest_descendent_index);
            }
        }
    }
}

void Heap::printHeap()
{
    for (int i = 1; i <= curr_size; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void Heap::swapElements(int parent_index, int child_index)
{
    int temp = heap[parent_index];
    heap[parent_index] = heap[child_index];
    heap[child_index] = temp;
}

int Heap::findMin()
{
    // first element is the miminum in a min max heap
    return heap[1];
}

int Heap::findMax()
{
    // one of the children of the root element is the maximum in a min max heap
    return max(heap[2], heap[3]);
}

void Heap::insertHeap(int new_element)
{
    if (isFull())
    {
        cout << "Heap Overflow" << endl;
    }
    else
    {
        int hole = ++curr_size;
        heap[hole] = new_element;
        BubbleUp(hole);
    }
}

void Heap::BubbleUp(int index)
{
    // if index is not on the root
    if (index != 1)
    {
        int parent_index = index / 2;
        // if index is on min level
        if (getLevelType(index))
        {
            if (heap[index] > heap[parent_index])
            {
                swapElements(parent_index, index);
                BubbleUpMax(parent_index);
            }
            else
            {
                BubbleUpMin(index);
            }
        }
        // if index is on max level
        else
        {
            if (heap[index] < heap[parent_index])
            {
                swapElements(parent_index, index);
                BubbleUpMin(parent_index);
            }
            else
            {
                BubbleUpMax(index);
            }
        }
    }
}

void Heap::BubbleUpMin(int index)
{
    int grandparent_index = index / 4;
    cout << "gp = " << grandparent_index << endl;
    // if grandparent exists
    if (grandparent_index >= 1)
    {
        if (heap[index] < heap[grandparent_index])
        {
            swapElements(grandparent_index, index);
            BubbleUpMin(grandparent_index);
        }
    }
}

void Heap::BubbleUpMax(int index)
{
    int grandparent_index = index / 4;
    // if grandparent exists
    if (grandparent_index >= 1)
    {
        if (heap[index] > heap[grandparent_index])
        {
            swapElements(grandparent_index, index);
            BubbleUpMax(grandparent_index);
        }
    }
}

// Function to convert the string input to a vector array.
// This way all the numbers (except whitespace and invalid characters)
// will be stored as individual integer elements in the array
vector<int> string_to_list(string s)
{
    vector<int> result;
    string vector_element = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            vector_element += s[i];
        }
        else if (vector_element != "")
        {
            try
            {
                int num = stoi(vector_element);
                // only positive integers are considered for our heap
                if (num > 0)
                {
                    result.push_back(num);
                }
            }
            catch (const invalid_argument &e)
            {
            }
            vector_element = "";
        }
    }
    if (vector_element != "")
    {
        int num = stoi(vector_element);
        if (num > 0)
        {
            result.push_back(num);
        }
    }
    return result;
}

void print_vector(vector<int> vec_arr)
{
    for (int i = 0; i < vec_arr.size(); i++)
    {
        cout << vec_arr[i] << " ";
    }
    cout << endl;
}