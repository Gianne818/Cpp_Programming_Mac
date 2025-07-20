#include <iostream>
#include <string>
using namespace std;

//Static data members are also known as "class variables".
//There is only one unique value of the variable for all objects inside the class

class OceanDepth {
public:
//since static variables are shared among all objects, they should be defined outside the class, as a global variable.
//they live in global memory that are scoped to a class. As such, only one instance of them should be created, by putting them outside the class definition.
    static int DepthMeters;
    static string DangerClass;

public:
    OceanDepth(int depthMeters){
        DepthMeters = depthMeters;
    }

    OceanDepth(){};

    void goDeeper(int deeperMeter){
        DepthMeters += deeperMeter;
    }

    void swimUpwards(int upwardsMeter){
        DepthMeters -= upwardsMeter;
    }

//Static member functions is independent of any object of the class, and can be called even if no objects exists
//Can be accessed via the ::
//Can access static members inside or outside the class
//Since they are independent from any object, they cannot access object-pointer, or the "this" pointer.
//It cannot access non-static members, since they would be associated with an object

    static void updateDangerClass() {
    if (DepthMeters <= 18)
        DangerClass = "Safe";
    else if (DepthMeters <= 30)
        DangerClass = "Caution";
    else if (DepthMeters <= 40)
        DangerClass = "Danger";
    else if (DepthMeters <= 60)
        DangerClass = "Extreme Danger";
    else
        DangerClass = "Lethal";
}

};


//:: is the scope resolution operator. It is used to access members of a class or namespace, or when differentiating global and local variables.
//Particuarly useful for static members of a class, since it is defined outside the class.
int OceanDepth::DepthMeters = 0;
string OceanDepth::DangerClass = "Safe";

int main (){
    OceanDepth o1 = (0);
    char input;
    int depthChange;
    
    while(1){
        cout << "\nDanger Class: " << o1.DangerClass << endl;
        cout << "You are currently " << o1.DepthMeters << "m deep. You are holding your friend's hand.";
        cout << "What do you want to do?\n";
        cout << "A.) Go deeper" << endl << "B.) Swim Up" <<  endl << "C.) Exit" << endl;
        cin >> input;

        if (tolower(input)=='a'){
            cout << "By how many meters? ";
            cin >> depthChange;
            o1.goDeeper(depthChange);
            o1.updateDangerClass();
        } 
        
        else if (tolower(input)=='b'){
            cout << "By how many meters? ";
            cin >> depthChange;
            o1.swimUpwards(depthChange);
            o1.updateDangerClass();
        } 
        
        else if (tolower(input)=='c'){
            cout << "Oh no you couldn't exit. There's a shark!" << endl;
            OceanDepth o2;
            cout << "The shark's depth: " << o2.DepthMeters << endl;
            cout << "You tried to flee again." << endl;
            getchar();

            while (o1.DepthMeters > 0){
                o1.swimUpwards(5);
                cout << "Your depth: " << o1.DepthMeters << endl;
                cout << "The shark's: " << o1.DepthMeters << endl;
                if(o1.DepthMeters < 0) break;
                cout << "Press enter to swim.";
                getchar();
            }

            cout << "\nThe shark followed you. You died.\n";
            return 0;

        }
        
        else {
            cout << "Not a valid input.\n";
        }
    }

    
    
}
