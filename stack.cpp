#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    stack<char> myStack;
    char c;
    while (ss >> c)
        myStack.push(c);

    while (!myStack.empty())
    {
        cout << myStack.top();
        myStack.pop();
    }

    // stack<int> myStack;
    // myStack.push(5);
    // myStack.push(7);
    // myStack.push(8);

    // myStack.pop();
    // myStack.pop();
    // myStack.pop();
    // cout << myStack.empty();
}