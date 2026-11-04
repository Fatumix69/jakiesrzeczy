#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int max_fi;

    cout << "Podaj ile liczb fi chcesz wyswietlic:\n";
    cin >> max_fi;

    long double* fi = new long double[max_fi];
    fi[0] = 1;
    fi[1] = 1;

    for(int i = 2; i <= max_fi-1; i++)
    {
        fi[i] = fi[i - 1] + fi[i - 2];
    }
    cout << setprecision(1000);

    //for(int i = 0; i <= max_fi; i++)
    //{
    //    cout << "Wyraz nr. " << i << ". " << fi[i] << "\n";
    //}

    cout << "Ostatnia liczba fi to: " << fi[max_fi-1] << "\n";

    delete[] fi;
    return 0;
}