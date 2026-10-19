#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <time.h>

// Biblioteka uzywana tylko jesli program bedzie kompilowany na windowsie
#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

int liczba;

int main(){
    
    cout << "Witaj w losowaniu! Za 3 sekundy nastapi zwolnienie blokady!" << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    srand(time(NULL));

    for (int i = 1; i <= 6; i++){

        liczba = rand()%49+1; 
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << liczba << endl;

        // Dla Windowsa
        #ifdef _WIN32
            MessageBeep(MB_OK); //Dzwiek powiadomienia windowsa

        // Dla Linuxa
        #else
            system("paplay /usr/share/sounds/ocean/stereo/bell-window-system.oga");
        #endif
    }

    return 0;
}