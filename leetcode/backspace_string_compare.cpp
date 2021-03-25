#include <iostream>

using namespace std;

class Solution
{
public:
    string backspace(string s)
    {
        string strStack;
        for (int i = 0; i < s.size(); i++)
        {
            // If the stack is not empty and the program spots a '#' in s string, then pop the stack
            if (s[i] == '#')
            {
                if (!strStack.size())
                    strStack.pop_back();
            }
            // Push a char into the string stack
            else
                strStack.push_back(s[i]);
        }
        return strStack;
    }
    bool backspaceCompare(string S, string T)
    {
        // Returns true if the S string matches with the T string
        return backspace(S) == backspace(T);
    }
};

int main()
{
    Solution solve;
    cout << solve.backspaceCompare("#", "y#f#");
}