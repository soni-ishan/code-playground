#include <stack>
#include <vector>
#include "expression_tree.h"

Node::Node()
    : data(""),
      left(NULL),
      right(NULL)
{
}

Node::Node(string newdata)
    : data(newdata),
      left(NULL),
      right(NULL)
{
}

Node::Node(string newData, Node *leftptr, Node *rightptr)
    : data(newData),
      left(leftptr),
      right(rightptr)
{
}

string Node::getData()
{
    return data;
}

Node *Node::goLeft()
{
    return left;
}

Node *Node::goRight()
{
    return right;
}

// Function to make expression tree from postfix expression
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
            Node *right_node = st.top();
            st.pop();
            Node *left_node = st.top();
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
    root = NULL;
}

Node *Tree::getRoot()
{
    return root;
}

// Function to print expression tree in preorder form
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->getData() << " ";
        preorder(root->goLeft());
        preorder(root->goRight());
    }
}

// Function to print expression tree in inorder form
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->goLeft());
        cout << root->getData() << " ";
        inorder(root->goRight());
    }
}

// Function to print expression tree in postorder form
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->goLeft());
        postorder(root->goRight());
        cout << root->getData() << " ";
    }
}

int evaluate_tree(Node *root)
{
    if (root != NULL)
    {
        try
        {
            int operand = stoi(root->getData());
            return operand;
        }
        catch (const invalid_argument &e)
        {
            int left_subtree = evaluate_tree(root->goLeft());
            int right_subtree = evaluate_tree(root->goRight());
            string op = root->getData();
            switch (op[0])
            {
            case '+':
                return right_subtree + left_subtree;
            case '-':
                return right_subtree - left_subtree;
            case '*':
                return right_subtree * left_subtree;
            case '/':
                return right_subtree / left_subtree;
            default:
                break;
            }
        }
    }
    return NULL;
}