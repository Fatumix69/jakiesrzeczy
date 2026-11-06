// Mateusz Dziekan, IWiK, LK2

// Kalkulator przyjmuje wspolrzedne 3 kolejnych wektorow, a nastepnie wykonuje obliczenia takie jak: 
// dlugosci wektorow, iloczyny skalarne, nierownosc Cauchy-Schwarz-Buniakowski, wektory jednostkowe, 
// dlugosci wektorow jednostkowych, iloczyny wektorowe, potrojny iloczyn skalarny mieszany oraz cosinusy kierunkowe

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstddef>
#include <stdexcept>
#include <limits>

// funkcja zerujaca male wartosci ktore przy 4 miejscach po przecinku wyswietlalyby 0.0000 albo -0.0000
double bez_minus_zera(double liczba)
{
    const double prog_wyswietlania = 0.00005;

    if (std::abs(liczba) < prog_wyswietlania)
    {
        return 0.0;
    }
    return liczba;
}

// struktura wektora 3D i dzialania na nim
struct Wektor_3D
{
    double x, y, z;

    // dlugosc wektora
    double policz_dlugosc() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    // iloczyn skalarny
    double policz_il_skalar(const Wektor_3D& drugi) const
    {
        return x * drugi.x + y * drugi.y + z * drugi.z;
    }

    // wektor jednostkowy
    Wektor_3D policz_jednostkowy() const
    {
        double L = policz_dlugosc();
        if (L == 0.0)
        {
            // dla wektora zerowego zwracamy 0 (placeholder), zeby nie bylo dzielenia przez 0
            return {0.0, 0.0, 0.0}; 
        }
        return {x / L, y / L, z / L};
    }

    // iloczyn wektorowy liczony za pomoca macierzy z wykorzystaniem rozwiniecia laplace'a
    Wektor_3D policz_il_wektor(const Wektor_3D& drugi) const
    {
        return 
        {
            y * drugi.z - z * drugi.y,
            -(x * drugi.z - z * drugi.x), // tutaj musi byc minus przez rozwiniecie laplace'a
            x * drugi.y - y * drugi.x
        };
    }

    // funkcja do wypisania wektora
    void wypisz_wektor(const std::string& nazwa) const 
    {
        std::cout << nazwa << " = [" << bez_minus_zera(x) << ", " << bez_minus_zera(y) << ", " << bez_minus_zera(z) << "]\n";
    }
};

struct Dane_il_skalarnych
{
    double AoB, BoC, CoA;
};

struct Dane_L_wektorow
{
    double LA, LB, LC;
};

struct Dane_wektorow_jednostkowych
{
    Wektor_3D VA1, VB1, VC1;
};

struct Dane_il_wektorowych
{
    Wektor_3D VAB, VBC, VCA;
};

void wypisz_dane(const Wektor_3D& VA, const Wektor_3D& VB, const Wektor_3D& VC)
{
    std::cout << "\nDane:\n";

    VA.wypisz_wektor("VA");
    VB.wypisz_wektor("VB");
    VC.wypisz_wektor("VC");
}

Dane_L_wektorow wyznacz_L_wektorow(const Wektor_3D& VA, const Wektor_3D& VB, const Wektor_3D& VC)
{
    double LA = VA.policz_dlugosc();
    double LB = VB.policz_dlugosc();
    double LC = VC.policz_dlugosc();

    std::cout << "\nDlugosci wektorow:\n";
    std::cout << "LA = " << LA << "\nLB = " << LB << "\nLC = " << LC << "\n";

    return {LA, LB, LC};
}

Dane_il_skalarnych wyznacz_il_skalarne(const Wektor_3D& VA, const Wektor_3D& VB, const Wektor_3D& VC)
{
    double AoB = VA.policz_il_skalar(VB);
    double BoC = VB.policz_il_skalar(VC);
    double CoA = VC.policz_il_skalar(VA);

    std::cout << "\nIloczyny skalarne:\n";
    std::cout << "VA o VB = " << bez_minus_zera(AoB) << "\nVB o VC = " << bez_minus_zera(BoC) << "\nVC o VA = " << bez_minus_zera(CoA) << "\n";

    return {AoB, BoC, CoA};
}

void wyznacz_nierownosc_CSB(const Dane_il_skalarnych& skalar, const Dane_L_wektorow& dlugosci)
{
    std::cout << "\nNierownosc Cauchy-Schwarz-Buniakowski:\n";
    std::cout << "|VA o VB| <= LA * LB;     " << std::abs(skalar.AoB) << " <= " << dlugosci.LA * dlugosci.LB << "\n";
    std::cout << "|VB o VC| <= LB * LC;     " << std::abs(skalar.BoC) << " <= " << dlugosci.LB * dlugosci.LC << "\n";
    std::cout << "|VC o VA| <= LC * LA;     " << std::abs(skalar.CoA) << " <= " << dlugosci.LC * dlugosci.LA << "\n";
}

// funkcja pomocnicza do wypisania wektora jednostkowego oraz sprawdzenia czy istnieje (czy nie jest zerowy)
void wypisz_wektor_jednostkowy(const std::string& nazwa, const Wektor_3D& wektor, double dlugosc_oryginalu)
{
    if (dlugosc_oryginalu == 0.0)
    {
        std::cout << nazwa << " nie istnieje (wektor zerowy)\n";
    }
    else
    {
        wektor.wypisz_wektor(nazwa);
    }
}

Dane_wektorow_jednostkowych wyznacz_wektory_jednostkowe(const Wektor_3D& VA, const Wektor_3D& VB, const Wektor_3D& VC, const Dane_L_wektorow& dlugosci)
{
    Wektor_3D VA1 = VA.policz_jednostkowy();
    Wektor_3D VB1 = VB.policz_jednostkowy();
    Wektor_3D VC1 = VC.policz_jednostkowy();

    std::cout << "\nWektory jednostkowe:\n";
    wypisz_wektor_jednostkowy("VA1", VA1, dlugosci.LA);
    wypisz_wektor_jednostkowy("VB1", VB1, dlugosci.LB);
    wypisz_wektor_jednostkowy("VC1", VC1, dlugosci.LC);
    
    return {VA1, VB1, VC1};
}

// funkcja pomocnicza do wypisania dlugosci wektora jednostkowego oraz sprawdzenia czy istnieje (czy nie jest zerowy)
void wypisz_L_wektora_jednostkowego(const std::string& nazwa, const Wektor_3D& wektor_jednostkowy, double dlugosc_oryginalu)
{
    if (dlugosc_oryginalu == 0.0)
    {
        std::cout << nazwa << " nie istnieje (wektor zerowy)\n";
    }
    else
    {
        std::cout << nazwa << " = " << wektor_jednostkowy.policz_dlugosc() << "\n";
    }
}

void wyznacz_dlugosci_wektorow_jednostkowych(const Dane_wektorow_jednostkowych& wektory_jednostkowe, const Dane_L_wektorow& dlugosci)
{
    std::cout << "\nDlugosci wektorow jednostkowych:\n";
    wypisz_L_wektora_jednostkowego("LA1", wektory_jednostkowe.VA1, dlugosci.LA);
    wypisz_L_wektora_jednostkowego("LB1", wektory_jednostkowe.VB1, dlugosci.LB);
    wypisz_L_wektora_jednostkowego("LC1", wektory_jednostkowe.VC1, dlugosci.LC);
}

Dane_il_wektorowych wyznacz_iloczyny_wektorowe(const Wektor_3D& VA, const Wektor_3D& VB, const Wektor_3D& VC)
{
    Wektor_3D VAB = VA.policz_il_wektor(VB);
    Wektor_3D VBC = VB.policz_il_wektor(VC);
    Wektor_3D VCA = VC.policz_il_wektor(VA);

    std::cout << "\nIloczyny wektorowe:\n";
    VAB.wypisz_wektor("VAB (VA x VB)");
    VBC.wypisz_wektor("VBC (VB x VC)");
    VCA.wypisz_wektor("VCA (VC x VA)");

    return {VAB, VBC, VCA};
}

void wyznacz_il_mieszany(const Wektor_3D& VA, const Wektor_3D& VB, const Wektor_3D& VC, const Dane_il_wektorowych& il_wektorowe)
{
    double VABC = il_wektorowe.VAB.policz_il_skalar(VC);
    double VBCA = il_wektorowe.VBC.policz_il_skalar(VA);
    double VCAB = il_wektorowe.VCA.policz_il_skalar(VB);

    std::cout << "\nPotrojny iloczyn skalarny mieszany:\n";
    std::cout << "VABC = " << bez_minus_zera(VABC) << "\nVBCA = " << bez_minus_zera(VBCA) << "\nVCAB = " << bez_minus_zera(VCAB) << "\n";
}

// funkcja pomocnicza do wypisania cosinusa oraz sprawdzenia czy istnieje (czy nie jest zerowy)
void wypisz_cosinus(const std::string& nazwa, const Wektor_3D& wektor_jednostkowy, double dlugosc_oryginalu)
{
    if (dlugosc_oryginalu == 0.0)
    {
        std::cout << "l, m, n dla " << nazwa << " nie istnieje (wektor zerowy)\n";
    }
    else
    {
        std::cout << "l, m, n dla "<< nazwa << " = " << bez_minus_zera(wektor_jednostkowy.x) << ", " << bez_minus_zera(wektor_jednostkowy.y) << ", " << bez_minus_zera(wektor_jednostkowy.z)  << "\n";
    }
}

// uzywam tutaj wektorow jednostkowych gdyz pokrywaja sie z cosinusami kierunkowymi
void wyznacz_cosinusy_kierunkowe(const Dane_wektorow_jednostkowych& wektory_jednostkowe, const Dane_L_wektorow& dlugosci)
{
    std::cout << "\nCosinusy kierunkowe:\n";
    wypisz_cosinus("VA", wektory_jednostkowe.VA1, dlugosci.LA);
    wypisz_cosinus("VB", wektory_jednostkowe.VB1, dlugosci.LB);
    wypisz_cosinus("VC", wektory_jednostkowe.VC1, dlugosci.LC);
}

// ustawiam ta wartosc na taka zeby chronila przed przepelnieniem w obliczeniach np x * x
const double max_wartosc_wspolrzednej = 1e100;

// funkcja pomocnicza, probuje zamienic tekst na liczbe, przy bledzie zwraca false i wpisuje powod do 'blad'
bool przetworz_liczbe(const std::string& tekst, double& wynik, std::string& blad)
{
    try
    {
        // inicjalizuje na 0 z bezpieczenstwa przed smieciowymi danymi
        std::size_t policzone_znaki = 0;

        // proba konwersji tekstu w liczbe rzeczywista
        double liczba = std::stod(tekst, &policzone_znaki);

        // sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr oraz wybranych znakow np "-"
        // np. jesli wpisane zostalo "12$", liczba znakow wynosi 3 ale liczba przetworzonych cyfr juz 2 
        if (policzone_znaki != tekst.length())
        {
            blad = "Uzyles niedozwolonych znakow lub liter!";
            return false;
        }
        // sprawdza czy liczba jest skonczona oraz czy nie jest zbyt duza
        if (!std::isfinite(liczba) || std::abs(liczba) > max_wartosc_wspolrzednej)
        {
            blad = "Liczba musi byc skonczona i nie wieksza niz 1e100 (10^100)!";
            return false;
        }

        wynik = liczba;
        return true;
    }
    // lapie bledy gdy liczba wychodzi poza limit wartosci jaka moze pomiescic double
    catch (const std::out_of_range&)
    {
        blad = "Twoja liczba jest poza zakresem!";
    }
    // lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
    catch (const std::invalid_argument&)
    {
        blad = "To nie jest liczba!";
    }
    return false;
}

// funkcja pomocnicza wczytujaca i walidujaca poprawnosc wpisanych wspolrzednych
double wczytaj_wspolrzedna(const std::string& wspolrzedna)
{
    std::string dane_wejsciowe;
    std::string blad;
    double liczba = 0.0;

    while (std::cin >> dane_wejsciowe)
    {
        if (przetworz_liczbe(dane_wejsciowe, liczba, blad))
        {
            return liczba;
        }
        std::cout << "BLAD! " << blad << " Musisz podac liczbe RZECZYWISTA. Sprobuj ponownie.\n";
        std::cout << wspolrzedna << " = ";
    }

    // strumien zamkniety (Ctrl+D / Ctrl+Z), nie ma juz skad czytac
    throw std::runtime_error("Przerwano wprowadzanie danych.");
}

// funkcja pomocnicza do podawania wspolrzednych wektorow
Wektor_3D podaj_wspolrzedne(const std::string& ktorego)
{
    std::cout << "\nPodaj wspolrzedne " << ktorego << ":\n";
    std::cout << "x = ";
    double x = wczytaj_wspolrzedna("x");
    std::cout << "y = ";
    double y = wczytaj_wspolrzedna("y");
    std::cout << "z = ";
    double z = wczytaj_wspolrzedna("z");

    return {x, y, z};
}

void obliczenia(const Wektor_3D& VA, const Wektor_3D& VB, const Wektor_3D& VC)
{
    wypisz_dane(VA, VB, VC);

    // 1. dlugosci wektorow
    Dane_L_wektorow dlugosci = wyznacz_L_wektorow(VA, VB, VC);

    // 2. iloczyny skalarne
    Dane_il_skalarnych skalary = wyznacz_il_skalarne(VA, VB, VC);

    // 3. nierownosc Cauchy-Schwarz-Buniakowski
    wyznacz_nierownosc_CSB(skalary, dlugosci);

    // 4. wektory jednostkowe
    Dane_wektorow_jednostkowych jednostki = wyznacz_wektory_jednostkowe(VA, VB, VC, dlugosci);

    // 5. dlugosci wektorow jednostkowych
    wyznacz_dlugosci_wektorow_jednostkowych(jednostki, dlugosci);

    // 6. iloczyny wektorowe
    Dane_il_wektorowych il_wektorowe = wyznacz_iloczyny_wektorowe(VA, VB, VC);

    // 7. potrojny iloczyn skalarny mieszany
    wyznacz_il_mieszany(VA, VB, VC, il_wektorowe);

    // 8. cosinusy kierunkowe
    wyznacz_cosinusy_kierunkowe(jednostki, dlugosci);
}

int main()
{
    try
    {
        // precyzja ustawiona na 4 liczby po przecinku
        std::cout << std::fixed << std::setprecision(4);

        std::cout << "\nWitaj w kalkulatorze wektorow 3D!\n";

        Wektor_3D VA = podaj_wspolrzedne("pierwszego wektora VA");
        Wektor_3D VB = podaj_wspolrzedne("drugiego wektora VB");
        Wektor_3D VC = podaj_wspolrzedne("trzeciego wektora VC");

        obliczenia(VA, VB, VC);

        std::cout << "\nNacisnij <Enter> zeby zakonczyc program";
        // zabezpieczenie przed przypadkowo wpisana spacja po wpisaniu ostatniej wspolrzednej
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }
    catch (const std::exception& e)
    {
        std::cout << "\n" << e.what() << "\n";
        return 1;
    }
    return 0;
}