#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <tuple>
#include <typeinfo>
#include <exception>
#include <algorithm>

using namespace std;

class InvalidPostfix : public exception
{
    virtual const char *what() const throw()
    {
        return "Postfix expression is invalid";
    }
} invalidPostfix;

class DivideByZero : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "Sorry, cannot divide by zero.";
    }

} dbzError;

tuple<int, int> popTwo(stack<int> &myStack, string expType)
{
    int last = myStack.top();
    myStack.pop();
    int second_last = myStack.top();
    myStack.pop();
    if (expType == "postfix")
        return {last, second_last};
    else
        return {second_last, last};
}

int main()
{

    string expType, line;
    cout << "Is the expression postfix, prefix, or infix? ";
    cin >> expType;
    cin.ignore();
    cout << "Enter expression: ";
    // Postfix: 2 3 1 * + 9 -
    // Prefix: -+8/632
    getline(cin, line);

    if (expType == "prefix")
        reverse(line.begin(), line.end());
    stringstream ss(line);
    stack<int> myStack;
    char c;
    while (ss >> c)
    {
        if (isdigit(c))
            myStack.push(c - '0');
        else
        {
            auto [last, slast] = popTwo(myStack, expType);
            switch (c)
            {
            case '*':
            {
                myStack.push(slast * last);
                break;
            }
            case '/':
            {
                myStack.push(slast / last);
                break;
            }
            case '+':
            {
                if (slast != 0)
                    myStack.push(slast + last);
                else
                    throw dbzError;
                break;
            }
            case '-':
            {
                myStack.push(slast - last);
                break;
            }
            default:
                throw invalidPostfix;
            }
        }
    }

    cout << myStack.top();
}