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

    // buildHeap and its assisting functions
    void buildHeap(string);
    bool getDescendentType(int, int);
    bool getLevelType(int);
    void TrickleDown(int);
    int getSmallestDescendent(int);
    void TrickleDownMin(int);
    int getLargestDescendent(int);
    void TrickleDownMax(int);

    void printHeap();
    void swapElements(int, int);

    int findMin();
    int findMax();

    void insertHeap(int);
    void BubbleUp(int);
    void BubbleUpMin(int);
    void BubbleUpMax(int);

    void deleteMin();
    void deleteMax();
};

// vector functions
vector<int> string_to_list(string);
void print_vector(vector<int>);

#endif