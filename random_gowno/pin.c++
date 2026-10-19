#include <iostream>
using namespace std;

double saldo = 3.60;
string PIN;

int main(){

    cout << "Witaj w naszym baku!" << endl;
    cout << "Podaj nr PIN:" << endl;
    cin >> PIN;
    
    /*if(PIN == "2137"){
        cout << "Udalo ci sie zalogowac" << endl;
        cout << "Twoj status konta to:" << saldo << endl;
    }
    else{
        cout << "Podano bledny PIN" << endl;
    }*/

    while(PIN != "2137"){
        cout << "Podano bledny PIN sproboj jeszcze raz." << endl;
        cin >> PIN;
    }

    cout << "Udalo ci sie zalogowac, twoj status konta to:" << saldo << endl;

    return 0;
}
