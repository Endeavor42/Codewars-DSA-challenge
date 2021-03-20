#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class LongestConsec
{
public:
    static string longestConsec(const vector<string> &strings, int k)
    {
        k = max(k, 0);
        string longest;
        for (size_t i = k; i <= strings.size(); i += 1)
        {
            auto begin = next(strings.begin(), i - k);
            auto end = next(begin, k);
            string s = accumulate(begin, end, string());
            if (s.length() > longest.length())
            {
                longest = s;
            }
        }
        return longest;
    }
};

int main()
{
    vector<string> s{"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
    cout << LongestConsec::longestConsec(s, 2);
}