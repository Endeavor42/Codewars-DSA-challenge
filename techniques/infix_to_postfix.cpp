#include <iostream>
#include <stack>
#include <exception>
#include <sstream>

using namespace std;

class InvalidOperator : public exception
{
    virtual const char *what() const throw()
    {
        return "Invalid operator";
    }
} invalidOperator;

bool isOperator(char c)
{
    switch (c)
    {
    case '*':
    case '/':
    case '+':
    case '-':
        return true;
    default:
        return false;
    }
}

bool hasHigherPrec(char top, char c)
{
    if (top == c)
        return true;
    auto check = [](char c) {
        switch (c)
        {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            throw invalidOperator;
        }
    };

    return check(top) >= check(c);
}

// Expression -> A + B * C - D * E -> ABC*+DE*-
// Expression -> ((A + B) * C - D) * E -> AB+C*D-E*
int main()
{
    stack<char> op_stack;
    cout << "Input expression: ";
    string line;
    getline(cin, line);
    stringstream exp(line);
    string s = "";
    char c;
    // Iterate through the expression
    while (exp >> c)
    {
        if (isOperator(c))
        {
            // while the stack is not empty and the top of the stack has higher precedence than the operator c, then pop the stack
            while (!op_stack.empty() && op_stack.top() != '(' && hasHigherPrec(op_stack.top(), c))
            {
                s += op_stack.top();
                op_stack.pop();
            }
            // Push the lower precedence to the stack, which is c
            op_stack.push(c);
        }
        // if c is not an operator but an open parenthesis, then push it to the stack
        else if (c == '(')
            op_stack.push(c);
        else if (!op_stack.empty() && c == ')')
        {
            while (op_stack.top() != '(')
            {
                s += op_stack.top();
                op_stack.pop();
            }
            op_stack.pop();
        }
        else
            s += c;
    }
    while (!op_stack.empty())
    {
        s += op_stack.top();
        op_stack.pop();
    }
    for (char l : s)
        cout << l << " ";
}