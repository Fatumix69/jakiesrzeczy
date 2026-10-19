#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

int main(){

    for (int i=30; i>=0; i--){

        this_thread::sleep_for(chrono::milliseconds(1000));

        //Dla Windowsa
        #ifdef _WIN32
            system("cls");
        
        //Dla Linux/macOS
        #else
            system("clear");
        #endif

        cout << i << endl;
    }
    cout << "JEBUT" << endl;

    return 0;
}