#include "heap.h"

void minHeap::buildHeap(string input)
{
    curr_length = 0;
    vector<int> element_list = string_to_list(input);
    for (int i = 0; i < element_list.size(); i++)
    {
        curr_length++;
        heap[curr_length] = element_list[i];
    }
    for (int i = curr_length / 2; i > 0; i--)
    {
        compare_parent_child(i);
    }
}

void minHeap::compare_parent_child(int parent_index)
{
    if (parent_index <= curr_length / 2)
    {
        int child_index = 2 * parent_index;
        if ((child_index < curr_length) && (curr_length % 2 == 1) && (heap[2 * parent_index + 1] < heap[2 * parent_index]))
        {
            child_index = 2 * parent_index + 1;
        }
        if (heap[child_index] < heap[parent_index])
        {
            swapElements(child_index, parent_index);
            compare_parent_child(child_index);
        }
    }
}

void minHeap::swapElements(int index1, int index2)
{
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

void minHeap::printHeap()
{
    for (int i = 1; i <= curr_length; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void minHeap::insertElement(int new_element)
{
    curr_length++;
    int new_element_index = curr_length;
    heap[new_element_index] = new_element;
    while (heap[new_element_index / 2] > heap[new_element_index])
    {
        swapElements(new_element_index, new_element_index / 2);
        new_element_index /= 2;
    }
}

int minHeap::findMin()
{
    return heap[1];
}

// int minHeap::findMax(int index)
// {
//     if (2 * index + 1 <= curr_length)
//     {
//         findMax(max(2 * index, 2 * index + 1));
//     }
//     return heap[index];
// }

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