#include <iostream>
#include <string>

using namespace std;

string dzialanie;

double a;
double b;
double c;

void dodawanie(){
    c = a + b;
}

void odejmowanie(){
    c = a - b;
}

void mnozenie(){
    c = a * b;
}

void dzielenie(){
    c = a / b;
}

int main(){
    string userInput;

    // Petla ktora sprawdza czy pierwsza liczba jest prawidlowa
    while (true) {
        cout << "Podaj pierwsza liczbe RZECZYWISTA i wcisnij <ENTER>" << endl;
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
                cout << "BLAD! Uzyles znakow lub liter! Musisz podac liczbe RZECZYWISTA. Sproboj ponownie." << endl << endl;
            }
        } 
        catch (...) {
            // Lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
            cout << "BLAD! To nie jest liczba. Musisz podac liczbe RZECZYWISTA. Sproboj Ponownie." << endl << endl;
        }
    }

    cout << "Podaj znak dzialania (+, -, *, /) i wcisnij <Enter>:" << endl;
    cin >> dzialanie;

    // Petla ktora sprawdza czy podany znak dzialania jest prawidlowy
    while(dzialanie != "+" && dzialanie != "-" && dzialanie != "*" && dzialanie != "x" && dzialanie != "/"){
        cout << "Podano nieprawidlowy znak dzialania, sproboj ponownie:" << endl;
        cin >> dzialanie;
    }

    // Petla ktora sprawdza czy druga liczba jest prawidlowa
    while (true) {
        cout << "Podaj druga liczbe RZECZYWISTA i wcisnij <ENTER>" << endl;
        cin >> userInput; 

        try {
            // Liczy jak duzo podanych znakow bylo cyframi
            size_t charactersProcessed;
            
            // Proba konwersji tekstu w liczbe rzeczywista (double)
            b = stod(userInput, &charactersProcessed);
            
            // Sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr
            // Np. jesli wpisane zostalo "12$"", liczba znakow wynosi 3 ale liczba cyfr 
            if (charactersProcessed == userInput.length()){
                
                // Liczba wszystkich znakow zgadza sie z liczba cyfr, zakancza petle
                break;
            } 
            else{

                // Liczba wszystkich znakow nie zgadza sie z liczba cyfr
                cout << "BLAD! Uzyles znakow lub liter! Musisz podac liczbe RZECZYWISTA. Sproboj ponownie." << endl;
            }
        } 
        catch (...) {
            // Lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
            cout << "BLAD! To nie jest liczba. Musisz podac liczbe RZECZYWISTA. Sproboj Ponownie." << endl;
        }
    }

    if(dzialanie == "+"){        
        dodawanie();
    }
    else if(dzialanie == "-"){
        odejmowanie();
    }
    else if(dzialanie == "*"){
        mnozenie();
    }
    else if(dzialanie == "x"){
        mnozenie();
    }
    else if(dzialanie == "/"){
        if(a != 0 && b != 0){
            dzielenie();
        }

        // Komunikat dla dzielenia przez zero
        else{
            cout << "Nie wolno dzielic przez zero!" << endl;
            cout << "Wcisnij <Enter> zeby zakonczyc program";
            cin.ignore();
            cin.get();
            return 0;
        }
    }

    cout << "Twoj wynik to: " << c << endl;
    cout << "Wcisnij <Enter> zeby zakonczyc program";
    cin.ignore();
    cin.get();

    return 0;
}