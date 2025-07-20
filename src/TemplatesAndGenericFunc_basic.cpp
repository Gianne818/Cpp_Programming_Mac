#include <iostream>
#include <string>
using namespace std;

//Generic functions are those defined with templates
//Function templates are functions that can operate with generic types
//Start with the keyword template, followed by keyword typename or class, then the name.
//<class T> and <typename T> are indistinct and behave the exact same way

template <typename T1>
//The swap function below can swap variables of different data types
void swapVars(T1& a, T1& b){
    T1 temp = a;
    a = b;
    b = temp;
}

template <class T2> //<class> behaves the exact same with <typename>
T2 getMax(T2 a, T2 b){
    return (a>b ? a : b );
}

int main (){
    int x = 5, y = 6;
    swapVars(x, y); //If template<typename t1, typename t2...> has multiple params, you need to explicitly define the types
    cout << "After swapping int:\n";
    cout << "X: " << x << endl << "Y: " << y << endl;

    cout << "Swap again to go back to original values of int:\n";
    swapVars <int> (x, y); //You can explicitly define the type that T1 is going to take.
    cout << "X: " << x << endl << "Y: " << y << endl << endl;


    char c = 'A', d = 'B';
    swapVars(x, y);
    cout << "After swapping char:\n";
    cout << "C: " << c << endl << "D: " << d << endl;
    
    cout << "Swap again to go back to original values of char:\n";
    swapVars <char> (c, d);
    cout << "C: " << c << endl << "D: " << d << endl << endl;

    float f1 = 10.2, f2 = 11.44;
    string s1 = "HATDOG", s2 = "Hetdog";
    cout << "Max of floats: " << getMax(f1, f2) << endl;
    cout << "Max of ints: " << getMax(x, y) << endl;
    cout << "Max of chars: " << getMax(c, d) << endl; //checks ascii value, A=65, B=66
    cout << "Max of strings: " << getMax(s1, s2) << endl; //Compares ascii val of first char of each strings, and if the same, proceeds to next char.
}