#include <iostream>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Bouncingball
{
public:
    static int bouncingBall(double h, double bounce, double window)
    {
        // base case
        if (h <= 0 || bounce <= 0 || bounce >= 1 || window >= h)
            return -1;
        return bouncingBall(h * bounce, bounce, window) + 2;
    }
};

int main()
{
    cout << Bouncingball::bouncingBall;
}
