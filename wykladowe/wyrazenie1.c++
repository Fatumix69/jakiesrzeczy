#include <iostream>
using namespace std;

int main(){

        double f, g, h;

        cout << "Podaj liczbę g:" << endl;
        cin >> g;

        cout << "Podaj liczbę h:" << endl;
        cin >> h;

        if (g == 0 || h == 0){
            cout << "Nie da rady" << endl;
        }
        else{

            f = (g + h) / (g * h);
            cout << "Wynik wyrazenia to:" << endl << f << endl;
        }
        return 0;
}
