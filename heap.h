#ifndef HEAP_H
#define HEAP_H
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_LENGTH = 1000;

class Heap
{
private:
    int heap[MAX_LENGTH];
    int curr_size;

public:
    bool isFull();

    int getElement(int);
    int getSmallerChild(int);
    int getLargerChild(int);
    int getSmallestDescendent(int);
    int getLargestDescendent(int);
    int getElementLevel(int);
    int getLevelType(int);
    bool getDescendentType(int, int);

    void TrickleDown(int);
    void TrickleDownMin(int);
    void TrickleDownMax(int);

    void buildHeap(string);
    void printHeap();

    void compare_parent_child(int);
    void swapElements(int, int);
    
    void insertHeap(int);
    void deleteMin();
    int findMax();
};

// vector functions
vector<int> string_to_list(string);
void print_vector(vector<int>);

#endif