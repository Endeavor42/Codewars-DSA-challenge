// # 946
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> pushed, vector<int> popped)
    {
        stack<int> st;
        // Iterate through the values of pushed
        for (int i = 0; auto val : pushed)
        {
            // iterate until we see that the value of pushed matches with the first element of popped
            if (val == popped[i])
            {
                ++i;
                // As long as the stack is not empty and the top of the stack matches with the current popped element
                // then pop the stack
                while (!st.empty() && st.top() == popped[i])
                {
                    st.pop();
                    i++;
                }
            }
            // If there's no match, then push the val into the stack
            else
                st.push(val);
        }
        // Empty stack indicates that the sequences are valid
        return st.empty();
    }
};

int main()
{
    Solution answer;
    cout << answer.validateStackSequences({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2});
}