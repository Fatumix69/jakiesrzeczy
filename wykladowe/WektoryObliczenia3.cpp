// Mateusz Dziekan, IWiK, LK2

// Kalkulator przyjmuje wspolrzedne 3 kolejnych wektorow, a nastepnie wykonuje obliczenia takie jak: 
// dlugosci wektorow, iloczyny skalarne, nierownosc Cauchy-Schwarz-Buniakowski, wektory jednostkowe, 
// dlugosci wektorow jednostkowych, iloczyny wektorowe, potrojny iloczyn skalarny mieszany oraz cosinusy kierunkowe

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <stdexcept>

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
struct Wektor3D
{
    double x, y, z;

    // dlugosc wektora
    double dlugosc() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }

    // iloczyn skalarny
    double il_skalar(const Wektor3D& drugi) const
    {
        return x * drugi.x + y * drugi.y + z * drugi.z;
    }

    // wektor jednostkowy
    Wektor3D jednostka() const
    {
        double L = dlugosc();
        if (L == 0.0)
        {
            // dla wektora zerowego zwracamy 0 (placeholder), zeby nie bylo dzielenia przez 0
            return {0.0, 0.0, 0.0}; 
        }
            return {x / L, y / L, z / L};
    }

    // iloczyn wektorowy liczony za pomoca macierzy z wykorzystaniem rozwiniecia laplace'a
    Wektor3D il_wektor(const Wektor3D& drugi) const
    {
        return 
        {
            y * drugi.z - z * drugi.y,
            -(x * drugi.z - z * drugi.x), // tutaj musi byc minus przez rozwiniecie laplace'a
            x * drugi.y - y * drugi.x
        };
    }

    // funkcja do wypisania wektora
    void wypisz(const std::string& nazwa) const 
    {
        std::cout << nazwa << " = [" << bez_minus_zera(x) << ", " << bez_minus_zera(y) << ", " << bez_minus_zera(z) << "]\n";
    }
};

struct Dane_skalarne
{
    double AoB, BoC, CoA;
};

struct Dane_dlugosci
{
    double LA, LB, LC;
};

struct Dane_wektory_jednostkowe
{
    Wektor3D VA1, VB1, VC1;
};

struct Dane_iloczyny_wektorowe
{
    Wektor3D VAB, VBC, VCA;
};

void wypisz_dane(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC)
{
    std::cout << "\nDane:\n";

    VA.wypisz("VA");
    VB.wypisz("VB");
    VC.wypisz("VC");
}

Dane_dlugosci wyznacz_dlugosci_wektorow(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC)
{
    double LA = VA.dlugosc();
    double LB = VB.dlugosc();
    double LC = VC.dlugosc();

    std::cout << "\nDlugosci wektorow:\n";
    std::cout << "LA = " << LA << "\nLB = " << LB << "\nLC = " << LC << "\n";

    return {LA, LB, LC};
}

Dane_skalarne wyznacz_iloczyny_skalarne(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC)
{
    double AoB = VA.il_skalar(VB);
    double BoC = VB.il_skalar(VC);
    double CoA = VC.il_skalar(VA);

    std::cout << "\nIloczyny skalarne:\n";
    std::cout << "VA o VB = " << bez_minus_zera(AoB) << "\nVB o VC = " << bez_minus_zera(BoC) << "\nVC o VA = " << bez_minus_zera(CoA) << "\n";

    return {AoB, BoC, CoA};
}

void wyznacz_nierownosc_cauchy_schwarz_buniakowski(const Dane_skalarne& skalar, const Dane_dlugosci& policzona_dlugosc)
{
    std::cout << "\nNierownosc Cauchy-Schwarz-Buniakowski:\n";
    std::cout << "|VA o VB| <= LA * LB;     " << std::abs(skalar.AoB) << " <= " << policzona_dlugosc.LA * policzona_dlugosc.LB << "\n";
    std::cout << "|VB o VC| <= LB * LC;     " << std::abs(skalar.BoC) << " <= " << policzona_dlugosc.LB * policzona_dlugosc.LC << "\n";
    std::cout << "|VC o VA| <= LC * LA;     " << std::abs(skalar.CoA) << " <= " << policzona_dlugosc.LC * policzona_dlugosc.LA << "\n";
}

// funkcja pomocnicza do wypisania wektora jednostkowego oraz sprawdzenia czy istnieje
void wypisz_wektor1(const std::string& nazwa, const Wektor3D& wektor, double dlugosc_oryginalu)
{
    if(dlugosc_oryginalu == 0.0)
    {
        std::cout << nazwa << " nie istnieje (wektor zerowy)\n";
    }
    else
    {
        wektor.wypisz(nazwa);
    }
}

Dane_wektory_jednostkowe wyznacz_wektory_jednostkowe(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC, const Dane_dlugosci& policzona_dlugosc)
{
    Wektor3D VA1 = VA.jednostka();
    Wektor3D VB1 = VB.jednostka();
    Wektor3D VC1 = VC.jednostka();

    std::cout << "\nWektory jednostkowe:\n";
    wypisz_wektor1("VA1", VA1, policzona_dlugosc.LA);
    wypisz_wektor1("VB1", VB1, policzona_dlugosc.LB);
    wypisz_wektor1("VC1", VC1, policzona_dlugosc.LC);
    
    return {VA1, VB1, VC1};
}

// funkcja pomocnicza do wypisania dlugosci wektorow jednostkowych oraz sprawdza czy istnieja
void wypisz_dlugosc1(const std::string& nazwa, const Wektor3D& wektor1, double dlugosc_oryginalu)
{
    if(dlugosc_oryginalu == 0.0)
    {
        std::cout << nazwa << " nie istnieje (wektor zerowy)\n";
    }
    else
    {
        std::cout << nazwa << " = " << wektor1.dlugosc() << "\n";
    }
}

void wyznacz_dlugosci_wektorow_jednostkowych(const Dane_wektory_jednostkowe& wektor1, const Dane_dlugosci& dlugosc)
{
    std::cout << "\nDlugosci wektorow jednostkowych:\n";
    wypisz_dlugosc1("LA1", wektor1.VA1, dlugosc.LA);
    wypisz_dlugosc1("LB1", wektor1.VB1, dlugosc.LB);
    wypisz_dlugosc1("LC1", wektor1.VC1, dlugosc.LC);
}

Dane_iloczyny_wektorowe wyznacz_iloczyny_wektorowe(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC)
{
    Wektor3D VAB = VA.il_wektor(VB);
    Wektor3D VBC = VB.il_wektor(VC);
    Wektor3D VCA = VC.il_wektor(VA);

    std::cout << "\nIloczyny wektorowe:\n";
    VAB.wypisz("VAB (VA x VB)");
    VBC.wypisz("VBC (VB x VC)");
    VCA.wypisz("VCA (VC x VA)");

    return {VAB, VBC, VCA};
}

void wyznacz_potrojny_iloczyn_skalarny_mieszany(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC, const Dane_iloczyny_wektorowe& policzony_il_wektorowy)
{
    double VABC = policzony_il_wektorowy.VAB.il_skalar(VC);
    double VBCA = policzony_il_wektorowy.VBC.il_skalar(VA);
    double VCAB = policzony_il_wektorowy.VCA.il_skalar(VB);

    std::cout << "\nPotrojny iloczyn skalarny mieszany:\n";
    std::cout << "VABC = " << bez_minus_zera(VABC) << "\nVBCA = " << bez_minus_zera(VBCA) << "\nVCAB = " << bez_minus_zera(VCAB) << "\n";
}

// funkcja pomocnicza do wypisania cosinusa oraz sprawdzenia czy istnieje
void wypisz_cosinus(const std::string& nazwa, const Wektor3D& wektor1, double dlugosc_oryginalu)
{
    if(dlugosc_oryginalu == 0.0)
    {
        std::cout << "l, m, n dla " << nazwa << " nie istnieje (wektor zerowy)\n";
    }
    else
    {
        std::cout << "l, m, n dla "<< nazwa << " = " << bez_minus_zera(wektor1.x) << ", " << bez_minus_zera(wektor1.y) << ", " << bez_minus_zera(wektor1.z)  << "\n";
    }
}

void cosinusy_kierunkowe(const Dane_wektory_jednostkowe& wektor1, const Dane_dlugosci& policzona_dlugosc)
{
    std::cout << "\nCosinusy Kierunkowe\n";
    wypisz_cosinus("VA", wektor1.VA1, policzona_dlugosc.LA);
    wypisz_cosinus("VB", wektor1.VB1, policzona_dlugosc.LB);
    wypisz_cosinus("VC", wektor1.VC1, policzona_dlugosc.LC);
}

// funkcja pomocnicza walidujaca poprawnosc wpisanych wspolrzednych
double wczytaj_liczbe_R(const std::string& wspolrzedna)
{
    std::string dane_wejsciowe;

    while(true) 
    {
        std::cin >> dane_wejsciowe; 

        try 
        {
            // liczy jak duzo podanych znakow bylo faktycznymi liczbami
            size_t policzone_znaki;
            
            // proba konwersji tekstu w liczbe rzeczywista
            double liczba = std::stod(dane_wejsciowe, &policzone_znaki);
            
            // sprawdza czy liczba wszystkich wpisanych znakow jest rowna liczbie cyfr
            // np. jesli wpisane zostalo "12$", liczba znakow wynosi 3 ale liczba przetworzonych cyfr juz 2 
            if(policzone_znaki == dane_wejsciowe.length())
            {
                // sprawdza czy liczba jest skonczona oraz czy nie jest zbyt duza
                if(std::isfinite(liczba) && std::abs(liczba) <= 1e100)
                {
                    return liczba;
                }
                else
                {
                    std::cout << "BLAD! Liczba musi byc SKONCZONA i nie wieksza niz 1e100. Sproboj ponownie.\n";
                    std::cout << wspolrzedna << " = ";
                }
            } 
            else
            {
                // liczba wszystkich znakow nie zgadza sie z liczba cyfr
                std::cout << "BLAD! Uzyles znakow lub liter! Musisz podac liczbe RZECZYWISTA. Sproboj ponownie.\n";
                std::cout << wspolrzedna << " = ";
            }
        }
        catch(std::out_of_range&)
        {
            std::cout << "BLAD! Twoja liczba jest za duza! Sproboj ponownie.\n";
            std::cout << wspolrzedna << " = ";
        }
        catch(...) 
        {
            // lapie bledy gdy uzytkownik wpisal sam tekst np "kaktus" albo "$"
            std::cout << "BLAD! To nie jest liczba. Musisz podac liczbe RZECZYWISTA. Sproboj Ponownie.\n";
            std::cout << wspolrzedna << " = ";
        }
    }
}

// funkcja pomocnicza do podawania wspolrzednych wektorow
Wektor3D podaj_wspolrzedne(const std::string& ktorego)
{
    double x, y, z;

    std::cout << "\nPodaj wspolrzedne " << ktorego << ":\n";
    std::cout << "x = ";
    x = wczytaj_liczbe_R("x");
    std::cout << "y = ";
    y = wczytaj_liczbe_R("y");
    std::cout << "z = ";
    z = wczytaj_liczbe_R("z");

    return {x, y, z};
}

void obliczenia(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC)
{
    wypisz_dane(VA, VB, VC);

    // 1. dlugosci wektorow
    Dane_dlugosci dlugosci = wyznacz_dlugosci_wektorow(VA, VB, VC);

    // 2. iloczyny skalarne
    Dane_skalarne skalary = wyznacz_iloczyny_skalarne(VA, VB, VC);

    // 3. nierownosc Cauchy-Schwarz-Buniakowski
    wyznacz_nierownosc_cauchy_schwarz_buniakowski(skalary, dlugosci);

    // 4. wektory jednostkowe
    Dane_wektory_jednostkowe jednostki = wyznacz_wektory_jednostkowe(VA, VB, VC, dlugosci);

    // 5. dlugosci wektorow jednostkowych
    wyznacz_dlugosci_wektorow_jednostkowych(jednostki, dlugosci);

    // 6. iloczyny wektorowe
    Dane_iloczyny_wektorowe policzone_il_wektorowe = wyznacz_iloczyny_wektorowe(VA, VB, VC);

    // 7. potrojny iloczyn skalarny mieszany
    wyznacz_potrojny_iloczyn_skalarny_mieszany(VA, VB, VC, policzone_il_wektorowe);

    // 8. cosinusy kierunkowe
    cosinusy_kierunkowe(jednostki, dlugosci);
}

int main()
{
    // precyzja ustawiona na 4 liczby po przecinku
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "\nWitaj w kalkulatorze wektorow 3D!\n";

    Wektor3D VA = podaj_wspolrzedne("pierwszego wektora VA");
    Wektor3D VB = podaj_wspolrzedne("drugiego wektora VB");
    Wektor3D VC = podaj_wspolrzedne("trzeciego wektora VC");

    obliczenia(VA, VB, VC);

    std::cout << "\nNacisnij <Enter> zeby zakonczyc program";
    std::cin.ignore();
    std::cin.get();

    return 0;
}