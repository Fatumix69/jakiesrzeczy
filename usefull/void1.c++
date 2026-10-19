#include <iostream>

using namespace std;

// beta() musi byc zdefiniowana na poczatku zeby gamma i alfa mogly ich uzyc
void beta(int n){
    int k;{
        short int j = 6;
        for(int i = 0; i < n; i++){
            cout << j;
        }
        cout << j;
    }
}

// gamma() musi byc zdefiniowana jako druga zeby alfa mogla jej uzyc
void gamma(double x, int m){
    beta(x);
    cout << m * x;
}

void alfa(){
    int c =7;
    beta(2);
    gamma(3.65, c);
}

// main() zeby zainicjowac alfe
int main(){
    alfa();
    
    return 0;
}