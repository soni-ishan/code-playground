#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
    string input;
    do
    {
        cout << "Enter expresion: ";
        getline(cin, input);
    } while (!check_input_validity(input));  

    string input_type = detect_input_type(input);
    string postfix_exp;
    if (input_type == "infix")
    {
        postfix_exp = infix_to_postfix(input);
    }
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