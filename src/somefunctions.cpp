#include <iostream>
#include <string>
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

int main (){
    cout << addNum(1, 2) << endl;
    cout << addNum (1.1, 2.2) << endl;
    cout << addNum(1, 2, 3);

}