#include "heap.h"

void Heap::buildHeap(string input)
{
    vector<int> element_list = string_to_list(input);
    heap_length = 0;
    for (auto i = 0; i < element_list.size(); i++)
    {
        int element = element_list[i];
        if (check_valid_int(element))
        {
            heap_length++;
            heap[heap_length] = element;
        }
    }
}

void Heap::TrickleDown(int index)
{
    if ((int(log2(index)) % 2) == 0)
        TrickleDownMin(index);
    else
        TrickleDownMax(index);
}

void Heap::TrickleDownMin(int index)
{
}

void Heap::TrickleDownMax(int index)
{
}

int Heap::findMin()
{
    return heap[1];
}

int Heap::findMax()
{
    return max(heap[2], heap[3]);
}

// Function to convert the string input to a vector array.
// This way all the numbers, brackets and operators (except whitespace)
// will be stored as individual string elements in the array
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
                result.push_back(num);
            }
            catch (const invalid_argument &e)
            {
            }
            vector_element = "";
        }
        else
        {
        }
    }
    if (vector_element != "")
    {
        int num = stoi(vector_element);
        result.push_back(num);
    }
    return result;
}

bool check_valid_int(int x)
{
    return (x > 0);
}