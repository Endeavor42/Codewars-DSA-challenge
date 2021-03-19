#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int stray(vector<int> numbers)
{
    map<int, int> counters;
    for (int i = 0; i < numbers.size(); i++)
        counters[numbers[i]] ? counters[numbers[i]] = 1 : counters[numbers[i]] += 1;

    for (auto item : counters)
        if (item.second == 1)
            return item.first;
    return -1;
}

// However, this method is inefficient because sorting needs to go through the whole array at least once
int stray_clever(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end());
    return (numbers[0] != numbers[1]) ? numbers.front() : numbers.back();
}

int stray_clever1(vector<int> numbers)
{
    int res = 0;
    for (int n : numbers)
        res ^= n;
    return res;
}

int main()
{
    cout << stray_clever(vector<int>{3, 2, 2});
}