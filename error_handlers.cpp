#include <iostream>
using namespace std;

// To check if the input characters are valid
bool check_char_validity(string exp)
{
    string valid_chars = "1234567890+-*/^() ";
    for (int i = 0; i < exp.length(); i++)
    {
        if (valid_chars.find(exp[i]) == string::npos)
        {
            cout << "Input string does not contain valid characters...Please try again....." << endl;
            return false;
        }
    }
    return true;
}

// To check if the number of opening and closing brackets
// are equal for an infix input
bool equal_brackets(string exp)
{
    int open_brackets = 0;
    int close_brackets = 0;
    size_t pos = 0;
    while (pos = exp.find("(", pos) != string::npos)
    {
        open_brackets++;
        pos++;
    }
    pos = 0;
    while (pos = exp.find(")", pos) != string::npos)
    {
        close_brackets++;
        pos++;
    }
    if (open_brackets != close_brackets)
    {
        cout << "INPUT ERROR!! The number of opening anf closing brackets in your entered infix expression are not the same...";
        cout << "Please try again....." << endl;
        return false;
    }
    return true;
}

// master function to run all the error handler
// functions at once
bool check_input_validity(string exp)
{
    return (check_char_validity(exp) && equal_brackets(exp));
}