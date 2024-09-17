#include <iostream>
#include "expression_tree.h"
using namespace std;

int main()
{
    string test_exp = "-12 13 +";
    Node* test_tree = makeTree(test_exp);
    cout << "Preorder: ";
    preorder(test_tree);
    cout << endl;
    cout << "Inorder: ";
    inorder(test_tree);
    cout << endl;
    cout << "Postorder: ";
    postorder(test_tree);
    cout << endl;
    return 0;
}