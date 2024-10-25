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
    void printHeap();
    void swapElements(int, int);

    // getter functions
    bool getLevelType(int);
    bool getDescendentType(int, int);
    int getSmallestDescendent(int);
    int getLargestDescendent(int);

    // buildHeap and its assisting functions
    void buildHeap(string);
    void TrickleDown(int);
    void TrickleDownMin(int);
    void TrickleDownMax(int);

    // insertHeap and its assisting functions
    void insertHeap(int);
    void BubbleUp(int);
    void BubbleUpMin(int);
    void BubbleUpMax(int);

    // find functions
    int findMin();
    int findMax();

    // delete functions
    void deleteMin();
    void deleteMax();
};

// vector functions
vector<int> string_to_list(string);
void print_vector(vector<int>);

#endif