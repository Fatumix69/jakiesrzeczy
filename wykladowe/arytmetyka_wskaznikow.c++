#include <iostream>

using namespace std;

int main() {
    double *q, *r, *s, *t, *u, *v;
    double a = 12.5, *p = &a;

    p + 2;
    q - 5;
    //r * 3
    //s / 6
    //4 + u;
    //9 - v;
    //p + q;
    //p * q;
    //p / q;
    //p - q;
    *p + 2;
    *(p + 2);
    p[2];

    cout << *p << endl;

    return 0;
}

int second(){

    double a = 12.15, *p, tab[20];

    *p + 2;
    *(p + 2);
    p[2];
    p = tab;

    return 0
}