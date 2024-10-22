#ifndef HEAP_H
#define HEAP_H
#pragma once
#include <iostream>
#include <vector>
using namespace std;

const int MAX_LENGTH = 1000;

template <class Type>
class minHeap
{
private:
    Type heap[MAX_LENGTH];
    int curr_size;

public:
    bool isFull();

    Type getElement(int);
    Type getSmallerChild(int);
    Type getLargerChild(int);

    void buildHeap(string);
    void printHeap();

    void swapElements(int, int);
    void compare_parent_child(int);

    void insertElement(Type);
    void deleteMin();
    Type findMax();
};

// vector functions
template <class Type> vector<Type> string_to_list(string);
template <class Type> void print_vector(vector<Type>);

template <class Type>
bool minHeap<Type>::isFull()
{
    return (curr_size == MAX_LENGTH);
}

template <class Type>
Type minHeap<Type>::getElement(int index)
{
    return heap[index];
}

template <class Type>
Type minHeap<Type>::getSmallerChild(int parent_index)
{
    Type left_child_index = 2 * parent_index;
    Type right_child_index = 2 * parent_index + 1;
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

template <class Type>
Type minHeap<Type>::getLargerChild(int parent_index)
{
    Type left_child_index = 2 * parent_index;
    Type right_child_index = 2 * parent_index + 1;
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

template <class Type>
void minHeap<Type>::buildHeap(string input)
{
    curr_size = 0;
    vector<Type> element_list = string_to_list<Type>(input);
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

template <class Type>
void minHeap<Type>::printHeap()
{
    for (int i = 1; i <= curr_size; i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

template <class Type>
void minHeap<Type>::swapElements(int parent_index, int child_index)
{
    Type temp = heap[parent_index];
    heap[parent_index] = heap[child_index];
    heap[child_index] = temp;
}

template <class Type>
void minHeap<Type>::compare_parent_child(int parent_index)
{
    if (parent_index <= curr_size / 2)
    {
        Type child_index = 2 * parent_index;
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

template <class Type>
void minHeap<Type>::insertElement(const Type new_element)
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

template <class Type>
void minHeap<Type>::deleteMin()
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

template <class Type>
Type minHeap<Type>::findMax()
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

template <class Type> vector<Type> string_to_list(string s)
{
    vector<Type> result;
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
                Type num = stoi(vector_element);
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
        Type num = stoi(vector_element);
        if (num > 0)
        {
            result.push_back(num);
        }
    }
    return result;
}


template <class Type> void print_vector(vector<Type> vec_arr)
{
    for (int i = 0; i < vec_arr.size(); i++)
    {
        cout << vec_arr[i] << " ";
    }
    cout << endl;
}

#endif