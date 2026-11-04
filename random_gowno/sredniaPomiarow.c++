#include <iostream>

using namespace std;

void sredniaPomiarow()
{
    float ilePomiarowFloat;
    string userInput;

    while (true) 
    {
        cout << "Podaj liczbe pomiarow" << endl;
        cin >> userInput;

        try 
        {
            // Liczy jak duzo podanych znakow bylo cyframi
            size_t charactersProcessed;
            
            // Proba konwersji tekstu w liczbe rzeczywista (double)
            ilePomiarowFloat = stod(userInput, &charactersProcessed);
            
            // Sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr
            // Np. jesli wpisane zostalo "12$"", liczba znakow wynosi 3 ale liczba cyfr 
            if (charactersProcessed == userInput.length() && ilePomiarowFloat > 0)
            {
                
                // Liczba wszystkich znakow zgadza sie z liczba cyfr, zakancza petle
                break;
            } 
            else
            {

                // Liczba wszystkich znakow nie zgadza sie z liczba cyfr
                cout << "BLAD! Uzyles znakow lub liter albo podales liczbe mniejsza od zera! Musisz podac liczbe CALKOWITA wieksza od zera. Sproboj ponownie." << endl;
            }
        } 
        catch (...) 
        {
            // Lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
            cout << "BLAD! To nie jest liczba. Musisz podac liczbe CALKOWITA wieksza od zera. Sproboj Ponownie." << endl;
        }
    }

    int ilePomiarow = static_cast<int>(ilePomiarowFloat);

    cout << "Twoja podana liczba pomiarow to: " << ilePomiarow << endl;

    float* pomiary = new float[ilePomiarow]; 
    float srednia, suma = 0;

    for(int i = 0; i < ilePomiarow ;i++)
    {
        cout << "Podaj pomiar nr " << i + 1 << ":" << endl;
        
        while (true) 
        {
            cin >> userInput;

            try 
            {
                // Liczy jak duzo podanych znakow bylo cyframi
                size_t charactersProcessed;
            
                // Proba konwersji tekstu w liczbe rzeczywista (double)
                pomiary[i] = stod(userInput, &charactersProcessed);
            
                // Sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr
                // Np. jesli wpisane zostalo "12$"", liczba znakow wynosi 3 ale liczba cyfr 
                if (charactersProcessed == userInput.length())
                {
                
                // Liczba wszystkich znakow zgadza sie z liczba cyfr, zakancza petle
                break;
                } 
                else
                {

                    // Liczba wszystkich znakow nie zgadza sie z liczba cyfr
                    cout << "BLAD! Uzyles znakow lub liter albo podales liczbe mniejsza od zera! Musisz podac liczbe RZECZYWISTA. Sproboj ponownie." << endl;
                }
            } 
            catch (...) 
            {
                // Lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
                cout << "BLAD! To nie jest liczba. Musisz podac liczbe RZECZYWISTA. Sproboj Ponownie." << endl;
            }
        }

        suma = suma + pomiary[i];
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