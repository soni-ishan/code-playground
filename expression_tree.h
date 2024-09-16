#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#pragma once
#include <iostream>
#include "converters.h"
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
    Node() : data(""), left(NULL), right(NULL) {}
    Node(string newdata) : data(newdata), left(NULL), right(NULL) {}
    Node(string, Node *, Node *);
};

// Tree class to link all the nodes/elements of an
// expression in the form of an expression tree
class Tree
{
private:
    Node *root;

public:
    Tree() : root(NULL) {}
    Tree(string);
    void preorder(Node *) const;
    void inorder(Node *) const;
    void postorder(Node *) const;
};

// Node constructor using parameters
Node::Node(string newdata, Node *leftptr, Node *rightptr)
    : data(newdata),
      left(leftptr),
      right(rightptr)
{
}

// Tree constructor using postfix expression
Tree::Tree(string postfix_exp)
{
    vector<string> exp_list = string_to_list(postfix_exp);
    stack<Node *> st;
    for (int i = 0; i < exp_list.size(); i++)
    {
        try
        {
            int operand = stoi(exp_list[i]);
            Node *operand_node = new Node(exp_list[i]);
            st.push(operand_node);
        }
        catch (const invalid_argument &e)
        {
            string node_head = exp_list[i];
            Node *left_node = st.top();
            st.pop();
            Node *right_node = st.top();
            st.pop();
            Node *sub_tree = new Node(exp_list[i], left_node, right_node);
            st.push(sub_tree);
        }
    }
    if (!st.empty())
    {
        root = st.top();
        st.pop();
    }
    else
    {
        root = nullptr;
    }
}

// Function to print expression tree in preorder form
void Tree::preorder(Node *node) const
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Function to print expression tree in inorder form
void Tree::inorder(Node *node) const
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

// Function to print expression tree in postorder form
void Tree::postorder(Node *node) const
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

#endif