#include <iostream>

using namespace std;

int main() {
    double *pd, *qd, *td, a = 3, b=5, c, d;
    int *ri, *si, *ti, i = 1, j = 4, k, m;

    td = nullptr;
    ti = nullptr;

    pd = &a;
    qd = &b;
    ri = &i;
    si = &j;
    c = i;
    k = a;
    td = (double*) ri;
    ti = reinterpret_cast < int* > (pd);
    *qd = *ri;
    *si = *pd;
    //pd = &i;
    //ri = &a;

    cout << td << endl;
    cout << ti << endl;


    return 0;
}

fcja1(double odwagi[]);
fcja1(double *odwagi);

fcja2(){
    double przewagi [135];
    fcja1();

    return 0
}