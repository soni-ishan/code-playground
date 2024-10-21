#ifndef HEAP_H
#define HEAP_H
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_SIZE = 1000;

class Heap
{
private:
    int heap[MAX_SIZE];
    int heap_length;
public:
    void buildHeap(string);
    void TrickleDown(int);
    void TrickleDownMin(int);
    void TrickleDownMax(int);
    int findMin();
    int findMax();
    void insertHeap(int);
    void deleteMin();
    void deleteMax();
};

vector<int> string_to_list(string);

// error handlers
bool check_valid_int(int);

#endif