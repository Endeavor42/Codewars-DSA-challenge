#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <typeinfo>
#include <cmath>

using namespace std;

int main()
{
    int num = 123;
    vector<int> digits;

    // separate the digits
    while (num)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    for (auto val : digits)
        cout << val << " ";
    cout << endl;

    // join the digits in reverse order
    int num2 = 0;
    for (int i = 0; i < digits.size(); i++)
        num2 += digits[digits.size() - i - 1] * pow(10, i);
    cout << num2;

    // -------------

    // string comment = "Hello World";
    // vector<int> v{1, 2, 3, 4};
    // v.erase(remove_if(v.begin(), v.end(), [](int i) { return i == 4; }), v.end());
    // for (auto val : v)
    //     cout << val << " ";

    // // --- Reverse Digits ---
    // int num = 123;
    // vector<int> digits;
    // while (num)
    // {
    //     digits.insert(digits.begin(), num % 10);
    //     num /= 10;
    // }

    // for (auto val : digits)
    //     cout << val << " ";

    // // --- Bus Stops ---

    // vector<pair<int, int>> busStops{{3, 0}, {9, 1}, {4, 10}, {12, 2}, {6, 1}, {7, 10}};
    // int passengers_left = 0;

    // for (auto busStop : busStops)
    //     passengers_left += busStop.first - busStop.second;
    // cout << passengers_left;

    // // --- Maximum and minimum elements
    // vector<int> v{1, 2, 3, 4, -7, 999, 5, 6};
    // cout << *max_element(v.begin(), v.end()) << '\n';
    // cout << *min_element(v.begin(), v.end()) << '\n';
}

// Clever answer - Bus Stops
unsigned int number(const std::vector<std::pair<int, int>> &busStops)
{
    return std::accumulate(busStops.begin(), busStops.end(), 0, [](unsigned int sum, auto i) { return sum + i.first - i.second; });
}