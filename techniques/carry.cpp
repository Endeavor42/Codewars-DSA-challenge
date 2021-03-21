#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{11, 15, 13};
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i] > 9)
        {
            if (i == v.size() - 1)
                v.push_back(0);
            v[i + 1] += v[i] / 10;
            v[i] = v[i] % 10;
        }
    }
    for (auto val : v)
        cout << val << " ";
}