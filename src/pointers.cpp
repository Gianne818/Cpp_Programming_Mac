#include <iostream>
using namespace std;

int main (){
    int s;
    cout << "Enter the size of the array: ";
    cin >> s;
    int* arr = new int[s];

    for (int i = 0; i<s; i++){
        cout << "Enter arr[" << i << "]: ";
        cin >> *(arr+i);
    }

    cout << "The array:\n";
    for (int i = 0; i<s; i++){
        cout << "arr[" << i << "]: " << *(arr+i) << endl;
    }

    delete[] arr;
}