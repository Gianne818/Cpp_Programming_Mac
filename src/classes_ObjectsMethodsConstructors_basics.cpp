#include <iostream>
#include <string>
using namespace std;


class bird {
    public:
    //Class objects
    float wingspan;
    string specie; 
    
    //Class methods
    void displayBird(){
        cout << "Specie: " << specie << endl << "Wingspan: " << wingspan << endl << endl;
    }

    //Constructors - special methods that automatically run once an object is created, needs to have same name as the class
    bird (float ws, string sp){
        wingspan = ws;
        specie = sp;
    }

    //Constructor Overloading - set default values, useful when no value is set; must have diff param.
    bird (){
        wingspan = 0.0;
        specie = "Unknown";
    }

};

//Define methods and constructors outside class
/*
bird::bird(float ws, string sp){
    wingspan = ws;
    specie = sp;
}

void bird::displayBird(){
    cout << "Specie: " << specie << endl << "Wingspan: " << wingspan << endl << endl;
*/

int main (){
    // bird b1, b2, b3;
    // b1.wingspan = 4.5;
    // b1.specie = "Budgie";
    // b2.wingspan = 5.5;
    // b2.specie = "Cockatiel";
    // b3.wingspan = 5.3;
    // b3.specie = "Green Cheek Conure";

    bird b1(4.5, "Budgie");
    bird b2(5.5, "Cockatiel");
    bird b3 (5.4, "Green Cheek Conure");
    bird b4;

    b1.displayBird();
    b2.displayBird();
    b3.displayBird();
    b4.displayBird();

}