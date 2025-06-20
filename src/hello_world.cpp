#include <iostream>
#include <string>
using namespace std;

int main () {
    int s;
    cout << "Enter the size of the array: ";
    cin >> s;
    int arr[s];
    int ind = 0;
    for (int &i : arr) {
        cout << "Enter arr[" << ind << "]: ";
        cin >> i;
        ind++;
    } 

    cout << "The array: ";
    for (int j : arr) {
        cout << j << " ";
    }

    cout << endl << "The size of the array in bytes: " << sizeof(arr);
    cout << endl << "The size of the array in number of elements: " << sizeof(arr)/sizeof(int);
}

