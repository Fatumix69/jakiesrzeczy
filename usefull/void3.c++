#include <iostream>

using namespace std;

void alfa();
void beta(int n);
void gamma(double x, int m);

int main(){
    alfa();
    
    return 0;
}

void alfa(){
    int c =7;
    beta(2);
    gamma(3.65, c);
}

void beta(int n){
    int k;{
        short int j = 6;
        for(int i = 0; i < n; i++){
            cout << j;
        }
        cout << j;
    }
}

void gamma(double x, int m){
    beta(x);
    cout << m * x;
}
