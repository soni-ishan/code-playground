#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#pragma once
#include <iostream>
#include "converters.h"
using namespace std;

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

Node::Node(string newdata, Node *leftptr, Node *rightptr)
    : data(newdata),
      left(leftptr),
      right(rightptr)
{
}

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

void Tree::preorder(Node *node) const
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}
void Tree::inorder(Node *node) const
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}
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