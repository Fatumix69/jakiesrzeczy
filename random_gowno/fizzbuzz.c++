#include <iostream>

using namespace std;

int main()
{
    for( int i = 1; i <= 101; i++)
    {
        if( i % 3 == 0 && i % 5 == 0)
        {
            cout << i << ". Fizzbuzz\n";
        }
        else if( i % 3 == 0)
        {
            cout << i << ". Fizz\n";
        }
        else if( i % 5 == 0)
        {
            cout << i << ". Buzz\n";
        }
        else
        {
            cout << i << ".\n";
        }
    }
    

    return 0;
}