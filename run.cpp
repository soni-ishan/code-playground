#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
<<<<<<< HEAD
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
=======
    string input_exp1 = "-12 + 13";
    string input_exp2 = "13 + 24 * 35 / 46";
    string input_exp3 = "( 4 + 8 ) * ( 6 - 5 ) / ( 3 - 2 ) * ( 2 + 2 )";
    string input_exp4 = "( ( ( ( 1 * ( 2 + 3 ) ) - 3 ) + 4 ) * 5 )";
    string my_exp = "1 + 2 * 3";
    
    string inp_exp;
    cin >> inp_exp;
    cout << detect_input_type(inp_exp) << endl;

    // cout << "Enter infix expression: " << endl;
    // cin >> input_exp;

    // string postfix_exp = infix_to_postfix(input_exp3);
    // Tree *exp_tree = new Tree(postfix_exp);
>>>>>>> refs/remotes/origin/main

    // cout << "Preorder/Prefix expression: ";
    // exp_tree->preorder(exp_tree->getRoot());
    // cout << endl;

    // cout << "Inorder/Infix expression: ";
    // exp_tree->inorder(exp_tree->getRoot());
    // cout << endl;

    // cout << "Postorder/Postfix expression: ";
    // exp_tree->postorder(exp_tree->getRoot());
    // cout << endl;

    // cout << "Evaluation of the expression represented by the expression tree = " << exp_tree->evaluate_tree(exp_tree->getRoot()) << endl;

    return 0;
}