#include <iostream>
using namespace std;

int main()
{

    // Declare a variable to store size of the array
    int size = 5;

    // Allocate memory for int type array in heap
    // Store the address of first element in the pointer
    int* variableLengthArray = new int[size];

    // Initialize value to the array
    for (int i = 0; i < size; i++) {
        variableLengthArray[i] = i+1;
    }

    // Print the array
    cout << "The elements in the array: ";
    for (int i = 0; i < size; i++) {
        cout << variableLengthArray[i] << " ";
    }

    // free the memory after usage
    delete[] variableLengthArray;

    return 0;
}