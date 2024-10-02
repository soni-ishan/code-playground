#include "heap.h"

Node::Node(int data)
    : element(-1),
      left_child(NULL),
      right_child(NULL)
{
}

Node::Node(int data)
    : element(data),
      left_child(NULL),
      right_child(NULL)
{
}

int Node::getElement()
{
    return element;
}

int Heap::findMin()
{
    return root->getElement();
}

// Function to convert the string input to a vector array.
// This way all the numbers, brackets and operators (except whitespace)
// will be stored as individual string elements in the array
vector<string> string_to_list(string s)
{
    vector<string> result;
    string vector_element = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            vector_element += s[i];
        }
        else if (vector_element != "")
        {
            result.push_back(vector_element);
            vector_element = "";
        }
    }
    if (vector_element != "")
    {
        result.push_back(vector_element);
    }
    return result;
}