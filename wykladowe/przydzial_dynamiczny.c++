#include <iostream>

using namespace std;

int main(){
    double *p;
    p = new double;      // tworzy obiekt double i zwraca wskaznik do niego

    int n;
    double *t;
    new double[n];       // tworzy n-elementowa tablice double i zwraca wskaznik do niej (czyli do 0 elementu)

    delete p;
    delete[] t;          // niszczy pokazywana tablice wskaznika (t) nie modyfikuje

    return 0;
}