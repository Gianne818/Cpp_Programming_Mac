#include <iostream>
#include <string>
using namespace std;

//Template is another way of creating functions or classes.
//They let you write a function or class that works with different data types.
//It is useful when you want something to work with different data types

template <typename T1, typename T2> // 'T' is a placeholder for the data type, but it doesnt have to be 'T'
//This is now a generic class/template class
class Animal {
public:
    T1 first;
    T2 second;
    
    //Constructor
    Animal (T1 f, T2 s){
        first = f;
        second = s;
    }

    template <typename T3>
    T3 add (T3 fir, T3 sec) {
        return fir+sec;
    }

    void display (){
        cout << "\nFirst: " << first << endl << "Second: " << second << endl;
    }
};

template <typename T>
class Calculator {
private:
    T a, b;
public: 
    Calculator (T a, T b){
        this->a = a;
        this->b = b;
    }

    T add (){
        return a+b;
    }

    T subtract (){
        return a-b;
    }

    T multiply (){
        return a*b;
    }

    T divide (){
        return a/b;
    }

};

int main (){
    Animal <string, int> a("Bird", 4);
    Animal <int, int> b(5, 6);
    a.display();
    cout << endl << "Result for b: " << b.add<int>(b.first, b.second);

    Animal <string, string> c("Bird", "Elephant"); //since Animal Constructor accepts T1 and T2, explicitly define the types
    cout << c.add(c.first, c.second);
    
    cout << endl << endl << "----------" << endl;
    cout << "Calculator:\n";
    Calculator<int>c1(10, 5);
    cout << "Addition: " << c1.add() << endl;
    cout << "Subtraction: " << c1.subtract() << endl;
    cout << "Multiplication: " << c1.multiply() << endl;
    cout << "Division: " << c1.divide() << endl;
    cout << endl;

    cout << endl << endl << "----------" << endl;
    cout << "Calculator:\n";
    Calculator<double>c2(21.63, 8.4);
    cout << "Addition: " << c2.add() << endl;
    cout << "Subtraction: " << c2.subtract() << endl;
    cout << "Multiplication: " << c2.multiply() << endl;
    cout << "Division: " << c2.divide() << endl;
    cout << endl;



}