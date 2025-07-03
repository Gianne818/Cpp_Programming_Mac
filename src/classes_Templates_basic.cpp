#include <iostream>
#include <string>
using namespace std;

//Template is another way of creating functions or classes.
//They let you write a function or class that works with different data types.

template <typename T1, typename T2> // 'T' is a placeholder for the data type, but it doesnt have to be 'T'
class Animal {
public:
    T1 first;
    T2 second;
    
    Animal (T1 f, T2 s){
        first = f;
        second = s;
    }

    template <typename T3>
    T3 add () {
        return first+second;
    }

    void display (){
        cout << "First: " << first << endl << "Second: " << second << endl;
    }
};

int main (){
    Animal<string, int> a("Bird", 4);
    Animal <int, int> b(5, 6);
    a.display();
    cout << endl << "Result for b: " << b.add<int>();
}