#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#pragma once
#include <iostream>
using namespace std;

// Node class to represent individual nodes/elements
// like numbers and operators in an expression tree
class Node
{
private:
    string data;
    Node *left;
    Node *right;
    friend class Tree;

public:
    Node();
    Node(string newdata);
    Node(string, Node *, Node *);
    string getData();
    Node *goLeft();
    Node *goRight();
};

class Tree
{
private:
    Node *root;

public:
    Tree(string);
    Node *getRoot();
};

#endif