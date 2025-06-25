#include <iostream>
#include <string>
using namespace std;

//Access specifiers should not be associated with security, "They only exist at compile time to prevent you from breaking things."
//They control how the members of a class can be accessed.

class bird {
    public: //Members can be accessed outside the class
        float wingspan;
        string specie; 
        
        void displayBird(){
            cout << "Specie: " << specie << endl << "Wingspan: " << wingspan << endl << endl;
        }

        bird (float ws, string sp){
            wingspan = ws;
            specie = sp;
        }

        bird (){
            wingspan = 0.0;
            specie = "Unknown";
        }

    private: //Members cannot be accessed outside class
        string scieName;

        void displayScieName(){
            cout << scieName << endl;
        }
        
    //Access private members of a class using a public method inside the same class. Done through encapsulation. More on this later.
    public: //public setter method for private member scieName
        void setScieName(string sn) {
            scieName = sn;
        }

        //Or another constuctor
        bird (float ws, string sp, string sn){
            wingspan = ws;
            specie = sp;
            scieName = sn;
        }

        void publicDisplayScieName(){
            cout << "Scientific Name: " << scieName <<  endl;
        }

};

int main (){
    bird b1(4.5, "Budgie");
    b1.setScieName("Melopsittacus undulatus");
    // b1.displayScieName(); ---error, displayScieName is a private method. Must be set public to use.
    b1.displayBird();


    bird b2(5.5, "Cockatiel", "Nymphicus hollandicus");
    b2.publicDisplayScieName(); //public method accessing a private class
    b2.displayBird();
    
}


//More on "protected" access specifier later.