#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <string>
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
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    float evaluate_tree(Node *);
};

// Converter functions
int precedence(string);
vector<string> string_to_list(string);
string infix_to_postfix(string);

string detect_input_type(string);

// Error handling functions
bool check_char_validity(string exp);
bool equal_brackets(string exp);
bool check_input_validity(string exp);

#endif