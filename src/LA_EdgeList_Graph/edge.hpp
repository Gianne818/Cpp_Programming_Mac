#include <cstdlib>
#include <iostream>
using namespace std;

class Edge {
private:
    int name;
    char origin;
    char destination;

    public:
    // ADD more methods as necessary
    
    Edge(int name, char origin, char destination){
        this->name = name;
        this->origin = origin;
        this->destination = destination;
    }
    
    void toString() {
        cout << name << " | (" << origin << " -> " << destination << ")";
    }
    
    int getName(){
        return name;
    }
    
    char getOrigin(){
        return origin;
    }
    
    char getDestination(){
        return destination;
    }
    
    void setName(int name){
        this->name = name;
    }
    
    void setOrigin(char origin){
        this->origin = origin;
    }
    
    void setDestination(char destination){
        this->destination = destination;
    }
};