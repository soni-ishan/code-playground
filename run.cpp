#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    string input_exp1 = "-12 + 13";
    string input_exp2 = "13 + 24 * 35 / 46";
    string input_exp3 = "( 4 + 8 ) * ( 6 - 5 ) / ( 3 - 2 ) * ( 2 + 2 )";
    string input_exp4 = "( ( ( ( 1 * ( 2 + 3 ) ) - 3 ) + 4 ) * 5 )";
    // cout << "Enter infix expression: " << endl;
    // cin >> input_exp;

    string postfix_exp = infix_to_postfix(input_exp4);
    Tree *exp_tree = new Tree(postfix_exp);

    cout << "Preorder/Prefix expression: ";
    exp_tree->preorder(exp_tree->getRoot());
    cout << endl;

    cout << "Inorder/Infix expression: ";
    exp_tree->inorder(exp_tree->getRoot());
    cout << endl;

    cout << "Postorder/Postfix expression: ";
    exp_tree->postorder(exp_tree->getRoot());
    cout << endl;

    cout << "Evaluation of the expression represented by the expression tree = " << exp_tree->evaluate_tree(exp_tree->getRoot()) << endl;

    return 0;
}