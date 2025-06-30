#include <iostream>
#include <string>
using namespace std;

//Virtual Functions are particularly useful when using pointers in classes. 
//Without virtual, C++ decides which function to call based on the pointer type, not the actual object type.
//With virtual, it checks the actual object the pointer is pointing to.

#include <iostream>
#include <string>
using namespace std;

class Smartphones {
    protected:
        string brand;
        string model;
        string networkTech;
        string displayType;
        string chipSet;
        
    public: 
        Smartphones (string m, string nt, string dt, string cs) {
            model = m;
            networkTech = nt;
            displayType = dt;
            chipSet = cs;
        }

        virtual void displayBrand(){
            cout << "Brand: " << brand << endl;
        }

        void nonVirtualDisplayBrand(){
            cout << "Brand: " << brand << endl;
        }
        
        virtual void displaySpecs (){
            cout << "Model: " << model << endl << "Network: " << networkTech << endl << "Display: " << displayType << endl << "Chipset: " << chipSet << endl << endl;
        }

        void nonVirtualDisplaySpecs (){
            cout << "Model: " << model << endl << "Network: " << networkTech << endl << "Display: " << displayType << endl << "Chipset: " << chipSet << endl << endl;
        }
};

class Apple: public Smartphones { 
private: 
    int m_yearReleased;
    float m_iosVersionOnRelease;
    string m_lineUpSeries;

public:
    //constructor
    Apple(string m, string nt, string dt, string cs, int yearReleased, float iosVersionOnRelease, string lineUpSeries): Smartphones (m, nt, dt, cs) {
        m_yearReleased = yearReleased;
        m_iosVersionOnRelease = iosVersionOnRelease;
        m_lineUpSeries = lineUpSeries;
    }

    void displayBrand(){
        cout << "Brand: Apple" << endl;
    }

    void nonVirtualDisplayBrand(){
            cout << "Brand: Apple" << endl;
        }

    void nonVirtualDisplaySpecs (){
        cout << "Year Released: " << m_yearReleased << endl << "iOS Version: " << m_iosVersionOnRelease << endl << "Line Up: " << m_lineUpSeries << endl;
        cout << "Model: " << model << endl << "Network: " << networkTech << endl << "Display: " << displayType << endl << "Chipset: " << chipSet << endl << endl;
    }

    void displaySpecs(){
        cout << "Year Released: " << m_yearReleased << endl << "iOS Version: " << m_iosVersionOnRelease << endl << "Line Up: " << m_lineUpSeries << endl;
        cout << "Model: " << model << endl << "Network: " << networkTech << endl << "Display: " << displayType << endl << "Chipset: " << chipSet << endl << endl;

    }
};


int main (){
    Smartphones* s;
    Apple a("Iphone 14 Pro Max", "5G", "OLED", "A16", 2022, 18.0, "14 Series");
    s = &a;

    cout << "Virtual Function Output: " << endl;
    s->displayBrand();
    s->displaySpecs();

    cout << "Non-Virtual Function Output: (Is the method from the Derived class)" << endl;
    s->nonVirtualDisplayBrand(); //Output value is blank since it is not defined in the constructor or Apple.
    s->nonVirtualDisplaySpecs();
    

}
