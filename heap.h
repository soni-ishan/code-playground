#ifndef HEAP_H
#define HEAP_H
#pragma once
#include <iostream>
#include <vector>
using namespace std;

const int MAX_LENGTH = 1000;

class minHeap
{
private:
    int heap[MAX_LENGTH];
    int curr_size;

public:
    int getElement(int);
    void buildHeap(string);
    void printHeap();
    void swapElements(int, int);
    void compare_parent_child(int);
    void insertElement(int);
    int findMin();
    int findMax();
    bool isFull();
    void deleteMin();
    int getSmallerChild(int);
    int getLargerChild(int);
};

// vector functions
vector<int> string_to_list(string);
void print_vector(vector<int>);

#endif