#include <iostream>
#include <string>
using namespace std;

//An abstract class is one where implementation of a function cannot be provided, i.e. it has atlst one pure virtual func.
//Pure virtual(abstract) functions is a virtual function where we must override the function in the derived class,
//else, the derived class will become an abstract class


//Class animal is an abstract class
class Animal {
public: 
    //equating a virtual func to 0 makes it a pure virtual
    //It forces all derived class to make an implementation of the function
    virtual void movement() = 0;
};

class Mammals: public Animal {
public:
    //It is absolutely necessary to implement movement(), else it will result to an error  
    void movement(){
        cout << "Mammals: Walk." << endl;
    }
};

class Fish: public Animal {
public: 
    void movement(){
        cout << "Fish: Swim." << endl;
    }

};

int main (){
    int s;
    cout << "How many animals?";
    cin >> s;

    int numMammal;
    int numFish;

    cout << "Enter the number of Mammals (0-" << s << "): ";
    cin >> numMammal;

    cout << "Enter the number of Fish (must be exactly " << s-numMammal << "): ";
    cin >> numFish;


    // Animal* animals = new Animal[s];
    //Above code is an error because you cannot have an array of abstract class

    //An array of abstract class is not allowed, but we can have an array of pointers which points to a pointer to an abstract class
    //Value of animals is the memory address of the first of the array of pointers 
    Animal** animals = new Animal*[s]; 

    for (int i = 0; i<numMammal; i++){
        animals[i] = new Mammals(); //"new" returns the mem address of Mammal object
    }

    for (int i = 0; i<numFish; i++){
        animals[i+numMammal] = new Fish(); 
    }

    for (int i = 0; i<s; i++){
        animals[i]->movement();
    }

}