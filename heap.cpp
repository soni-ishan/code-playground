#include "heap.h"

void minHeap::buildHeap(string input)
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
        compare_parent_child(i);
    }
}

void minHeap::compare_parent_child(int parent_index)
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

void minHeap::swapElements(int parent_index, int child_index)
{
    int temp = heap[parent_index];
    heap[parent_index] = heap[child_index];
    heap[child_index] = temp;
}

void minHeap::printHeap()
{
    for (int i = 1; i <= curr_size; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void minHeap::insertElement(const int new_element)
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

int minHeap::findMin()
{
    return heap[1];
}

void minHeap::deleteMin()
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

int minHeap::getElement(int index)
{
    return heap[index];
}

int minHeap::getSmallerChild(int parent_index)
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

int minHeap::getLargerChild(int parent_index)
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

int minHeap::findMax()
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

bool minHeap::isFull()
{
    return (curr_size == MAX_LENGTH);
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