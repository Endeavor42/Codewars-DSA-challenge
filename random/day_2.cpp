#include <iostream>
#include <vector>
#include <map>

using namespace std;

int stray(vector<int> numbers)
{
    for (int i = 0; i < numbers.size() - 1; i++)
        if (numbers[i] != numbers[i - 1] && numbers[i + 1])
            return numbers[i];

    return 0;
}

int main()
{
    stray(vector<int>{1, 1, 2});
}