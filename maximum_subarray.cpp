// Given an integer array nums, find the contigious subarray (containing at least one number) which has the largest sum and return its sum.
#include <iostream>
#include <vector>
#include <limits>
#include <numeric>

using namespace std;

int main()
{
    int max_total = numeric_limits<int>::min();
    vector<int> nums = {-1, 1, -3, 4, -1, 2, 1, -5, 4};
    for (int i = 0; i < nums.size(); i++)
    {
        int total = 0;
        for (int j = i; j < nums.size(); j++)
        {
            total = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
        }
        // max_total = total > max_total ? total : max_total;
        max_total = total > max_total ? total : max_total;
    }
    cout << max_total;
}
