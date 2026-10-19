#include <iostream>

using namespace std;

int uczniowie, cukierki, x, y;

int main() {

    cout << "Ilu uczniow jest w Twojej klasie:";
    cin >> uczniowie;

    cout << "Ile cukierków kupila mama:";
    cin >> cukierki;
    
    x = cukierki / (uczniowie-1);
    cout << "Cukierkow dla kazdego ucznia:" << x << endl;

    y = cukierki - x * (uczniowie-1);
    cout << "Dla Jasia na wieczor:" << y << endl;

    return 0;
}