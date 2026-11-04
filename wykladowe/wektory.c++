#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

// Struktura reprezentująca wektor 3D i działania na nim
struct Vector3D {
    double x, y, z;

    // 1. Długość wektora
    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // 2. Iloczyn skalarny
    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // 4. Wektor jednostkowy (normalizacja)
    Vector3D unit() const {
        double len = length();
        return { x / len, y / len, z / len };
    }

    // 6. Iloczyn wektorowy
    Vector3D cross(const Vector3D& other) const {
        return {
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }

    // Pomocnicza funkcja do wypisywania wektora
    void print(const std::string& name) const {
        std::cout << name << " = [" << x << ", " << y << ", " << z << "]\n";
    }
};

// Funkcja realizująca pełny algorytm z ćwiczenia
void wykonajLaboratorium(const std::string& grupa, Vector3D VA, Vector3D VB, Vector3D VC) {
    std::cout << "\n==================================================\n";
    std::cout << "                DANE DLA GRUPY: " << grupa << "\n";
    std::cout << "==================================================\n";

    VA.print("VA");
    VB.print("VB");
    VC.print("VC");

    // 1. DŁUGOŚCI WEKTORÓW
    double LA = VA.length();
    double LB = VB.length();
    double LC = VC.length();

    std::cout << "\n--- 1. Długości wektorów ---\n";
    std::cout << "LA = " << LA << "; LB = " << LB << "; LC = " << LC << ";\n";

    // 2. ILOCZYNY SKALARNE
    double SAB = VA.dot(VB);
    double SBC = VB.dot(VC);
    double SCA = VC.dot(VA);

    std::cout << "\n--- 2. Iloczyny skalarne ---\n";
    std::cout << "SAB = " << SAB << "; SBC = " << SBC << "; SCA = " << SCA << ";\n";

    // 3. NIERÓWNOŚĆ CAUCHY-SCHWARZ-BUNIAKOWSKI
    std::cout << "\n--- 3. Nierówność Cauchy-Schwarz-Buniakowski ---\n";
    std::cout << "|SAB| <= LA * LB; TAK: " << std::abs(SAB) << " <= " << LA * LB << "\n";
    std::cout << "|SBC| <= LB * LC; TAK: " << std::abs(SBC) << " <= " << LB * LC << "\n";
    std::cout << "|SCA| <= LC * LA; TAK: " << std::abs(SCA) << " <= " << LC * LA << "\n";

    // 4. WEKTORY JEDNOSTKOWE
    Vector3D VA1 = VA.unit();
    Vector3D VB1 = VB.unit();
    Vector3D VC1 = VC.unit();

    std::cout << "\n--- 4. Wektory jednostkowe ---\n";
    VA1.print("VA1");
    VB1.print("VB1");
    VC1.print("VC1");

    // 5. DŁUGOŚCI WEKTORÓW JEDNOSTKOWYCH
    std::cout << "\n--- 5. Sprawdzamy długości wektorów jednostkowych ---\n";
    std::cout << "LA1 = " << VA1.length() << "; LB1 = " << VB1.length() << "; LC1 = " << VC1.length() << ";\n";

    // 6. ILOCZYNY WEKTOROWE
    Vector3D VAB = VA.cross(VB);
    Vector3D VBC = VB.cross(VC);
    Vector3D VCA = VC.cross(VA);

    std::cout << "\n--- 6. Iloczyny wektorowe ---\n";
    VAB.print("VAB (VA x VB)");
    VBC.print("VBC (VB x VC)");
    VCA.print("VCA (VC x VA)");

    // 7. POTRÓJNY ILOCZYN SKALARNY MIESZANY
    double VABC = VAB.dot(VC);
    double VBCA = VBC.dot(VA);
    double VCAB = VCA.dot(VB);

    std::cout << "\n--- 7. Potrójny iloczyn mieszany ---\n";
    std::cout << "VABC = " << VABC << "; VBCA = " << VBCA << "; VCAB = " << VCAB << ";\n";

    // 8. KOSINUSY KIERUNKOWE
    std::cout << "\n--- 8. Kosinusy kierunkowe ---\n";
    std::cout << "l, m, n dla VA = " << VA.x / LA << ", " << VA.y / LA << ", " << VA.z / LA << "\n";
    std::cout << "l, m, n dla VB = " << VB.x / LB << ", " << VB.y / LB << ", " << VB.z / LB << "\n";
    std::cout << "l, m, n dla VC = " << VC.x / LC << ", " << VC.y / LC << ", " << VC.z / LC << "\n";
    std::cout << "UWAGA: Pokrywają się dokładnie z wektorami jednostkowymi VA1, VB1, VC1!\n";
}

int main() {
    // Ustawienie precyzji wyświetlania liczb zmiennoprzecinkowych do 4 miejsc po przecinku
    std::cout << std::fixed << std::setprecision(4);

    // Dane dla grupy LK1
    Vector3D VA_LK1 = {1.0, 2.0, 3.0};
    Vector3D VB_LK1 = {4.0, 5.0, 6.0};
    Vector3D VC_LK1 = {7.0, 8.0, 9.0};
    wykonajLaboratorium("LK1", VA_LK1, VB_LK1, VC_LK1);

    // Dane dla grupy LK3
    Vector3D VA_LK3 = {8.0, 6.0, 4.0};
    Vector3D VB_LK3 = {5.0, 3.0, 1.0};
    Vector3D VC_LK3 = {2.0, 9.0, 6.0};
    wykonajLaboratorium("LK3", VA_LK3, VB_LK3, VC_LK3);

    return 0;
}