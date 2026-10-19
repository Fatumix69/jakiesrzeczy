#include <iostream>

using namespace std;

// 1. Function Prototypes (The Promise)
// You must declare the return type, function name, and parameter types.
double calculateArea(double length, double width);
void printResult(double area);

// 2. Main Function
int main() {
    double l = 5.5;
    double w = 3.0;

    // The compiler allows these calls because it already saw the prototypes
    double area = calculateArea(l, w);
    printResult(area);

    return 0;
}

// 3. Function Definitions (The Implementation)
// This is where you actually write what the functions do.
double calculateArea(double length, double width) {
    return length * width;
}

void printResult(double area) {
    cout << "The area is: " << area << endl;
}