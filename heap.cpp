#include "heap.h"

bool Heap::isFull()
{
    return (curr_size == MAX_LENGTH);
}

int Heap::getElement(int index)
{
    return heap[index];
}

int Heap::getSmallerChild(int parent_index)
{
    int left_child_index = 2 * parent_index;
    int right_child_index = 2 * parent_index + 1;
    if (left_child_index <= curr_size)
    {
        if (right_child_index <= curr_size)
        {
            if (heap[left_child_index] < heap[right_child_index])
            {
                return left_child_index;
            }
            return right_child_index;
        }
        return left_child_index;
    }
    return parent_index;
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

    // initialize the smallest_descendent_index as the left_child_index
    int largest_descendent_index = left_child_index;

    // check if element has two children
    if (right_child_index <= curr_size)
    {
        // get the smaller of the left and right children
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
                // if second child present, compare with smallest_descent_index
                largest_descendent_index = max(largest_descendent_index, right_left_child_index);
                // check if the right child has one child
                if (left_right_child_index <= curr_size)
                {
                    // if one child present, compare with largest_descendent_index
                    largest_descendent_index = max(largest_descendent_index, left_right_child_index);
                    // check if right child has a second child
                    if (right_right_child_index <= curr_size)
                    {
                        // if second child present, compare with smallest_descent_index
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

bool Heap::getDescendentType(int index, int descendent_index)
{
    // assuming we know that element at descendent_index is either child or grandchild of element at index
    return (descendent_index <= 2 * index + 1);
    // if true then element is child
    // if false then element is grandchild
}

int Heap::getLargerChild(int parent_index)
{
    int left_child_index = 2 * parent_index;
    int right_child_index = 2 * parent_index + 1;
    if (left_child_index <= curr_size)
    {
        if (right_child_index <= curr_size)
        {
            if (heap[left_child_index] < heap[right_child_index])
            {
                return right_child_index;
            }
            return left_child_index;
        }
        return left_child_index;
    }
    return parent_index;
}

int Heap::getElementLevel(int index)
{
    return log2(index);
}

int Heap::getLevelType(int index)
{
    return (getElementLevel(index) % 2 == 0);
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

void Heap::TrickleDownMin(int index)
{
    if (index <= curr_size / 2)
    {
        int smallest_descendent_index = getSmallestDescendent(index);
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
        else
        {
            if (heap[smallest_descendent_index] < heap[index])
            {
                swapElements(index, smallest_descendent_index);
            }
        }
    }
}

void Heap::TrickleDownMax(int index)
{
    if (index <= curr_size / 2)
    {
        int largest_descendent_index = getLargestDescendent(index);
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
        else
        {
            if (heap[largest_descendent_index] > heap[index])
            {
                swapElements(index, largest_descendent_index);
            }
        }
    }
}

void Heap::buildHeap(string input)
{
    curr_size = 0;
    vector<int> element_list = string_to_list(input);
    for (int i = 0; i < element_list.size(); i++)
    {
        curr_size++;
        heap[curr_size] = element_list[i];
    }
    for (int i = curr_size / 2; i > 0; i--)
    {
        TrickleDown(i);
        cout << "good " << i << " : " << heap[i] << endl;
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

void Heap::compare_parent_child(int parent_index)
{
    if (parent_index <= curr_size / 2)
    {
        int child_index = 2 * parent_index;
        if ((child_index < curr_size) && (curr_size % 2 == 1) && (heap[2 * parent_index + 1] < heap[2 * parent_index]))
        {
            child_index = 2 * parent_index + 1;
        }
        if (heap[child_index] < heap[parent_index])
        {
            swapElements(parent_index, child_index);
            compare_parent_child(child_index);
        }
    }
}

void Heap::swapElements(int parent_index, int child_index)
{
    int temp = heap[parent_index];
    heap[parent_index] = heap[child_index];
    heap[child_index] = temp;
}

void Heap::insertHeap(const int new_element)
{
    if (isFull())
    {
        cout << "Heap Overflow" << endl;
    }
    else
    {
        int hole = ++curr_size;
        for (; hole > 1 && new_element < heap[hole / 2]; hole /= 2)
        {
            heap[hole] = heap[hole / 2];
        }
        heap[hole] = new_element;
    }
}

void Heap::deleteMin()
{
    int hole = 1;
    int last_element = heap[curr_size];
    while (hole <= curr_size / 2)
    {
        int smaller_child_index = getSmallerChild(hole);
        swapElements(hole, smaller_child_index);
        hole = smaller_child_index;
    }
    if (hole != curr_size)
    {
        swapElements(hole, curr_size);
    }
    curr_size--;
}

int Heap::findMax()
{
    int mark = 1;
    while (mark <= curr_size / 2)
    {
        int larger_child_index = getLargerChild(mark);
        if (mark == larger_child_index)
        {
            return heap[mark];
        }
        mark = larger_child_index;
    }
    return heap[mark];
}

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