#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    for(int i=1; i<=10; i++)
    {
        int n;
        double wynik;
        n++;

        //wynik = -n * (2 + pow(-1, n));
        //wynik = pow(-2, n) + 3;
        //wynik = (sqrt(pow(n, 2) + 1) + n);
        //wynik = sqrt(pow(n, 2) + 1) - sqrt(pow(n, 2) - 1);
        //wynik = 1 / (sqrt(n + 1) - sqrt(n - 1));
        //wynik = (sqrt(pow(n, 2) + 1) + sqrt(n)) / (n - pow((pow(n, 2) + 8), (1.0 / 3.0)));
        //wynik = (sqrt(pow(n, 2) + 1) + sqrt(n)) * (pow(n, 2) + (n * pow((pow(n, 2) + 8), (1.0 / 3.0))) + (pow((pow(n, 2) + 8), (1.0 / 3.0))));
        wynik = pow(n, 3) - (pow(n, 2) + 8);

        cout << wynik << endl;
    }

    return 0;
}