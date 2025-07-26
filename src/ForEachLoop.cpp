#include <iostream>
#include <string>
using namespace std;

int main () {
    int s;
    cout << "Enter the size of the array: ";
    cin >> s;
    float arr[s]; //not good since in standard c++ specification, variable length arrays are not supported, and must be hardcoded
    int ind = 0;
    for (auto &i : arr) { //better to use reference & to create alias instead of copy, more efficient
        cout << "Enter arr[" << ind << "]: ";
        cin >> i;
        ind++;
    } 
    /*
    for (auto const &i : arr){} better use const to not modify value of arr
    */

    cout << "The array: ";
    for (int j : arr) {
        cout << j << " ";
    }

    cout << endl << "The size of the array in bytes: " << sizeof(arr);
    cout << endl << "The size of the array in number of elements: " << sizeof(arr)/sizeof(int);
}

