#include <iostream>
#include "expression_tree.h"
using namespace std;

int main()
{
    string input_exp;
    cout << "Enter infix expression: " << endl;
    cin >> input_exp;

    string postfix_exp = infix_to_postfix(input_exp);
    Tree *exp_tree = new Tree(postfix_exp);

    cout << "Preorder/Prefix expression: ";
    preorder(exp_tree->getRoot());
    
    cout << "Inorder/Infix expression: ";
    inorder(exp_tree->getRoot());

    cout << "Postorder/Postfix expression: ";
    postorder(exp_tree->getRoot());

    return 0;
}