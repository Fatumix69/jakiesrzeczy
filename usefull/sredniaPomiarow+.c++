#include <iostream>
#include <string>

using namespace std;

// funkcja do sprawdzenia czy liczba jest calkowita i dodatnia
int czy_liczba_dodatnia_Z()
{
    string userInput;

    while (true) 
    {
        cin >> userInput; 
        try 
        {
            // Liczy jak duzo podanych znakow bylo cyframi
            size_t charactersProcessed;
            
            // Proba konwersji tekstu w liczbe calkowita
            int liczba = stoi(userInput, &charactersProcessed);
            
            // Sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr
            // Np. jesli wpisane zostalo "12$"", liczba znakow wynosi 3 ale liczba cyfr 
            if (charactersProcessed == userInput.length() && liczba > 0)
            {
                // zwraca faktyczna liczbe i przerywa petle
                return liczba;
            } 
            else
            {

                // Liczba wszystkich znakow nie zgadza sie z liczba cyfr
                cout << "BLAD! Uzyles znakow lub liter! Musisz podac liczbe CALKOWITA wieksza od zera. Sproboj ponownie." << endl;
            }
        } 
        catch (...) {
            // Lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
            cout << "BLAD! To nie jest liczba. Musisz podac liczbe CALKOWITA wieksza od zera. Sproboj Ponownie." << endl;
        }
    }
}

// funkcja do sprawdzenia czy liczba jest rzeczywista
float czy_liczba_R()
{
    string userInput;

    while (true) 
    {
        cin >> userInput; 

        try {
            // Liczy jak duzo podanych znakow bylo cyframi
            size_t charactersProcessed;
            
            // Proba konwersji tekstu w liczbe rzeczywsita
            float liczba = stof(userInput, &charactersProcessed);
            
            // Sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr
            // Np. jesli wpisane zostalo "12$"", liczba znakow wynosi 3 ale liczba cyfr 
            if (charactersProcessed == userInput.length())
            {
                // zwraca faktyczna liczbe i przerywa petle
                return liczba;
            } 
            else
            {

                // Liczba wszystkich znakow nie zgadza sie z liczba cyfr
                cout << "BLAD! Uzyles znakow lub liter! Musisz podac liczbe RZECZYWISTA. Sproboj ponownie." << endl;
            }
        } 
        catch (...) {
            // Lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
            cout << "BLAD! To nie jest liczba. Musisz podac liczbe RZECZYWISTA. Sproboj Ponownie." << endl;
        }
    }
}

void sredniaPomiarow()
{
    cout << "Podaj liczbe pomiarow: " << endl;
    int ilePomiarow = czy_liczba_dodatnia_Z();

    cout << "Twoja liczba pomiarow to:" << ilePomiarow << endl;

    //dynamicznie rezerwuje nowe miejsce w pamieci zeby uzytkownik mogl podac ilosc miejsca w tablicy
    float* pomiary = new float[ilePomiarow]; 
    float srednia, suma = 0;

    for(int i = 0; i < ilePomiarow ;i++)
    {
        cout << "Podaj pomiar nr " << i + 1 << ":" << endl;
        pomiary[i] = czy_liczba_R();

        //robi to samo co: suma = suma + pomiary[i]
        suma += pomiary[i];
    }
    srednia = suma / ilePomiarow;

    cout << "Srednia twoich pomiarow to: " << srednia << endl;

    delete[] pomiary;
}

int main()
{
    sredniaPomiarow();
    return 0;
}