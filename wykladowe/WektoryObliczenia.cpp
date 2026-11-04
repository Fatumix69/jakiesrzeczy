// Mateusz Dziekan, IWiK, LK2

// Kalkulator przyjmuje wspolrzedne 3 kolejnych wektorow, a nastepnie wykonuje obliczenia takie jak: 
// dlugosci wektorow, iloczyny skalarne, nierownosc Cauchy-Schwarz-Buniakowski, wektory jednostkowe, 
// dlugosci wektorow jednostkowych, iloczyny wektorowe, potrojny iloczyn skalarny mieszany oraz cosinusy kierunkowe

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

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

    // wektor jednostowy
    Wektor3D jednostka() const
    {
        double L = dlugosc();
        if (L == 0.0)
        {
            // dla wektora zerowego zwracamy 0, zeby nie bylo dzielenia przez 0
            return { 0.0, 0.0, 0.0}; 
        }
        else
        {
            return { x / L, y / L, z / L };
        }
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

    // funkcja zamieniajaca -0.0 na 0.0
    double bezMinusZera(double liczba) const
    {
        if (liczba == 0.0)
        {
            return 0.0;
        }
        return liczba;
    }

    // funkcja do wypisania wektora
    void wypisz(const std::string& nazwa) const 
    {
        std::cout << nazwa << " = [" << bezMinusZera(x) << ", " << bezMinusZera(y) << ", " << bezMinusZera(z) << "]\n";
    }
};

void obliczenia(const Wektor3D& VA, const Wektor3D& VB, const Wektor3D& VC)
{
    std::cout << "\nDane:\n";

    VA.wypisz("VA");
    VB.wypisz("VB");
    VC.wypisz("VC");

    // dlugosci wektorow
    double LA = VA.dlugosc();
    double LB = VB.dlugosc();
    double LC = VC.dlugosc();

    std::cout << "\nDlugosci wektorow:\n";
    std::cout << "LA = " << LA << "\nLB = " << LB << "\nLC = " << LC << "\n";

    // iloczyny skalarne
    double AoB = VA.il_skalar(VB);
    double BoC = VB.il_skalar(VC);
    double CoA = VC.il_skalar(VA);

    std::cout << "\nIloczyny skalarne:\n";
    std::cout << "VA o VB = " << AoB << "\nVB o VC = " << BoC << "\nVC o VA = " << CoA << "\n";

    // nierownosc cauchy-schwarz-buniakowski
    std::cout << "\nNierownosc Cauchy-Schwarz-Buniakowski:\n";
    std::cout << "|VA o VB| <= LA * LB;     " << std::abs(AoB) << " <= " << LA * LB << "\n";
    std::cout << "|VB o VC| <= LB * LC;     " << std::abs(BoC) << " <= " << LB * LC << "\n";
    std::cout << "|VC o VA| <= LC * LA;     " << std::abs(CoA) << " <= " << LC * LA << "\n";

    // wektory jednostkowe
    Wektor3D VA1 = VA.jednostka();
    Wektor3D VB1 = VB.jednostka();
    Wektor3D VC1 = VC.jednostka();

    std::cout << "\nWektory jednostkowe:\n";
    VA1.wypisz("VA1");
    VB1.wypisz("VB1");
    VC1.wypisz("VC1");

    // dlugosci wektorow jednostkowych
    double LA1 = VA1.dlugosc();
    double LB1 = VB1.dlugosc();
    double LC1 = VC1.dlugosc();

    std::cout << "\nDlugosci wektorow jednostkowych:\n";
    std::cout << "LA1 = " << LA1 << "\nLB1 = " << LB1 << "\nLC1 = " << LC1 << "\n";


    // iloczyny wektorowe
    Wektor3D VAB = VA.il_wektor(VB);
    Wektor3D VBC = VB.il_wektor(VC);
    Wektor3D VCA = VC.il_wektor(VA);

    std::cout << "\nIloczyny wektorowe:\n";
    VAB.wypisz("VAB (VA x VB)");
    VBC.wypisz("VBC (VB x VC)");
    VCA.wypisz("VCA (VC x VA)");

    // potrojny iloczyn skalarny mieszany
    double VABC = VAB.il_skalar(VC);
    double VBCA = VBC.il_skalar(VA);
    double VCAB = VCA.il_skalar(VB);

    std::cout << "\nPotrojny iloczyn skalarny mieszany:\n";
    std::cout << "VABC = " << VABC << "\nVBCA = " << VBCA << "\nVCAB = " << VCAB << "\n";

    // cosinusy kierunkowe
    // zeby nie bylo dzielenia przez zero podstawiam wartosci z wektorow jednostkowych poniewaz i tak sie z nimi pokrywaja
    std::cout << "\nCosinusy Kierunkowe\n";
    std::cout << "l, m, n dla VA = " << VA1.x << ", " << VA1.y << ", " << VA1.z << "\n";
    std::cout << "l, m, n dla VB = " << VB1.x << ", " << VB1.y << ", " << VB1.z << "\n";
    std::cout << "l, m, n dla VC = " << VC1.x << ", " << VC1.y << ", " << VC1.z << "\n";
}

// funkcja pomocnicza do podawania wspolrzednych wektorow
Wektor3D wczytajWektor(const std::string& ktorego)
{
    double x, y, z;
    std::cout << "\nPodaj wspolrzedne " << ktorego << ":\n";
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;
    std::cout << "z = ";
    std::cin >> z;

    return {x, y, z};
}

int main()
{
    // precyzja ustawiona na 4 liczby po przecinku
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "\nWitaj w kalkulatorze wektorow 3D!\n";

    Wektor3D VA = wczytajWektor("pierwszego wektora VA");
    Wektor3D VB = wczytajWektor("drugiego wektora VB");
    Wektor3D VC = wczytajWektor("trzeciego wektora VC");
    obliczenia(VA, VB, VC);

    // funkcja zeby nie znikal terminal po wykonaniu obliczen na windowsie
    std::cout << "\nNacisnij <Enter> zeby zakonczyc program";
    std::cin.ignore();
    std::cin.get();

    return 0;
}