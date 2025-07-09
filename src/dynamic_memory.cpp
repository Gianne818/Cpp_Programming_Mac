#include <iostream>
#include <string>
using namespace std;

//the "new" operatir allocates memory on the heap and returns a pointer to that memory

int main (){
    int* p = new int; //allocate memory for one int
    *p = 35;

    cout << p; //display value of p, which is the address of int, returned by "new"
    cout << endl << &p; //display the address of pointer p
    cout << endl << *p << endl; //display value of the address stored in pointer p

    delete p; //remove memory allocated

    int s;
    cout << "Enter the number of elements of the array: ";
    cin >> s;

    //Value of this is a memory address of the first element of an array of int
    int* arr = new int[s]; //allocate memory for s number of int;
    
    for (int i = 0; i<s; i++){
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "The array:\n";
    for (int i = 0; i<s; i++){
        cout << arr[i] << endl;
    }

    delete[] arr;
}