#include <iostream>
#include <string>
#include <functional>
using namespace std;

struct Person {
    string name; 
    int age;
};

void swapNumbers(int* a, int* b){
    *a = (*a)*(*b); // 30
    *b = (*a)/(*b); //5
    *a = (*a)/(*b);

}
void modifyString (string &name){
    name += " World!";
}

void printName(Person p){
    cout << "The person is " << p.name << " and their age is " << p.age << " years old.";
}

//function overloading
double addNum (double a, double b){
    return a+b;
}

int addNum (int a, int b){
    return a+b;
}

int addNum (int a, int b, int c){
    return a+b+c;
}


//Lamda
void sampleFunctionLambda (function<int(int a, int b)> myFunc){

    cout << myFunc(1, 2);
}

int main (){
    string hi = "The result is: ";
    auto myFunc = [&hi](int a, int b) {
        cout << hi;
        return a+b;
    };

    sampleFunctionLambda(myFunc);
    cout << endl;
    hi = "Yes the result is this: ";
    sampleFunctionLambda(myFunc);
}


