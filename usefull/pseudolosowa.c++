#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h> 

using namespace std;

int liczba, strzal, ile_prob = 0;

int main()
{
    cout << "Witaj! Pomyslalem sobie liczbe od 1 do 100" << endl;
    srand(time(NULL));
    liczba = rand() % 100 + 1;
    //cout << liczba << endl;

    while(strzal != liczba){

        ile_prob++;
        cout << "Zgadnij jaka (to twoja " << ile_prob << " proba): " << endl;
        cin >> strzal;

        if(strzal == liczba){

            cout << "Udalo ci sie zgadnac liczbe w " << ile_prob <<" probie! Wygrales nowy iphone 69s" << endl;
        }

        else if(strzal < liczba){

            cout << "Moja liczba jest wieksza od twojej" << endl;
        }

        else if(strzal > liczba){

            cout << "Moja liczba jest mniejsza od twojej" << endl;
        }
    }

    getchar(); getchar(); //Dla pewnosci 2 razy zeby nie zniknela konsola

    return 0;
}