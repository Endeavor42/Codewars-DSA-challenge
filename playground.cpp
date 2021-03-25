#include <iostream>
#include <stack>
#include <exception>

using namespace std;

class DivideByZero : public exception
{
    virtual const char *what() const throw()
    {
        return "Cannot divide by zero.";
    }
} dbzError;

int main()
{
    int dividend = 3;
    int divisor = 0;
    if (divisor == 0)
        throw dbzError;
}