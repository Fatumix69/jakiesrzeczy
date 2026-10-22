#include <iostream>
#include <string>

using namespace std;

int main()
{
    string userInput;
    double a;

    while (true) {
        cout << "Podaj liczbe 'a': " << endl;
        cin >> userInput; 

        try {
            // Liczy jak duzo podanych znakow bylo cyframi
            size_t charactersProcessed;
            
            // Proba konwersji tekstu w liczbe rzeczywista (double)
            a = stod(userInput, &charactersProcessed);
            
            // Sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr
            // Np. jesli wpisane zostalo "12$"", liczba znakow wynosi 3 ale liczba cyfr 
            if (charactersProcessed == userInput.length()){
                
                // Liczba wszystkich znakow zgadza sie z liczba cyfr, zakancza petle
                break;
            } 
            else{

                // Liczba wszystkich znakow nie zgadza sie z liczba cyfr
                cout << "BLAD! Uzyles znakow lub liter! Musisz podac liczbe rzeczywista. Sproboj ponownie." << endl;
            }
        } 
        catch (...) {
            // Lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
            cout << "BLAD! To nie jest liczba. Musisz podac liczbe rzeczywista. Sproboj Ponownie." << endl;
        }
    }

    cout << "Udalo ci sie, twoja liczba wynosi: " << a << endl;

    return 0;
}