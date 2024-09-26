#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// Function to check operator precedence
int precedence(string op)
{
    if (op == "^")
    {
        return 3;
    }
    else if (op == "*" || op == "/")
    {
        return 2;
    }
    else if (op == "+" || op == "-")
    {
        return 1;
    }
    return -1;
}

// Function to convert the string input to a vector array.
// This way all the numbers, brackets and operators (except whitespace)
// will be stored as individual string elements in the array
vector<string> string_to_list(string s)
{
    vector<string> result;
    string vector_element = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            vector_element += s[i];
        }
        else
        {
            result.push_back(vector_element);
            vector_element = "";
        }
    }
    result.push_back(vector_element);
    return result;
}

// Function to convert the infix expression to postfix
string infix_to_postfix(string exp)
{
    vector<string> exp_list = string_to_list(exp);
    stack<string> st;
    string postfix = "";
    for (int i = 0; i < exp_list.size(); i++)
    {
        try
        {
            int operand = stoi(exp_list[i]);
            postfix += exp_list[i] + " ";
        }
        catch (const invalid_argument &e)
        {
            if (exp_list[i] == "(")
            {
                st.push(exp_list[i]);
            }
            else if (exp_list[i] == ")")
            {
                while (!st.empty() && st.top() != "(")
                {
                    postfix += st.top() + " ";
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && (precedence(st.top()) >= precedence(exp_list[i])))
                {
                    postfix += st.top() + " ";
                    st.pop();
                }
                st.push(exp_list[i]);
            }
        }
    }
    while (!st.empty())
    {
        postfix += st.top() + " ";
        st.pop();
    }
    postfix.pop_back();
    return postfix;
}