#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    reverse(line.begin(), line.end());
    cout << line;
    // stringstream ss(line);
    // stack<int> myStack;
}