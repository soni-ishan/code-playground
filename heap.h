#ifndef HEAP_H
#define HEAP_H
#pragma once
#include <iostream>
#include <vector>
using namespace std;

// const int MAX_LENGTH = 1000;

class Node
{
private:
    int element;
    Node *left_child;
    Node *right_child;

public:
    Node();
    Node(int);
    int getElement();
};

class Heap
{
private:
    Node *root;

public:
    void buildHeap(string);
    int findMin();
    int findMax();
    void insertHeap(int);
    void deleteMin();
    void deleteMax();
    bool duplicateElement(int);
};

// class Heap
// {
// private:
//     int* heap[MAX_LENGTH];
//     int heap_length;
// public:
//     void buildHeap(string);
//     int findMin();
//     int findMax();
//     void insertHeap(int);
//     void deleteMin();
//     void deleteMax();
// };

vector<string> string_to_list(string);

#endif