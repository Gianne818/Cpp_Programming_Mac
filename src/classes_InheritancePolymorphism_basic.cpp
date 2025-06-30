#include <iostream>
#include <string>
using namespace std;

//Inheritance allows one class to reuse attributes and methods from another class.
class Smartphones {
    protected:
        string brand;
        string model;
        string networkTech;
        string displayType;
        string chipSet;
    public: 
        Smartphones (string br, string m, string nt, string dt, string cs) {
            brand = br;
            model = m;
            networkTech = nt;
            displayType = dt;
            chipSet = cs;
        }

        Smartphones (string m, string nt, string dt, string cs) {
            model = m;
            networkTech = nt;
            displayType = dt;
            chipSet = cs;
        }

        void displayBrand(){
            cout << "Brand: " << brand << endl;
        }
        
        void displaySpecs (){
            cout << "Model: " << model << endl << "Network: " << networkTech << endl << "Display: " << displayType << endl << "Chipset: " << chipSet << endl << endl;
        }
};

//setting it into "private Smartphones" will make it so that all public members from Smartphones becomes private
class Apple: public Smartphones { 
private: 
    int m_yearReleased;
    float m_iosVersionOnRelease;
    string m_lineUpSeries;

public:
    //constructor
    Apple(string br, string m, string nt, string dt, string cs, int yearReleased, float iosVersionOnRelease, string lineUpSeries): Smartphones (br, m, nt, dt, cs) {
        m_yearReleased = yearReleased;
        m_iosVersionOnRelease = iosVersionOnRelease;
        m_lineUpSeries = lineUpSeries;
    }

    Apple(string m, string nt, string dt, string cs, int yearReleased, float iosVersionOnRelease, string lineUpSeries): Smartphones (m, nt, dt, cs) {
        m_yearReleased = yearReleased;
        m_iosVersionOnRelease = iosVersionOnRelease;
        m_lineUpSeries = lineUpSeries;
    }

    void displayBrand(){
        cout << "Brand: Apple" << endl;
    }

    //Polymorphism is the ability of an object to take on many forms or behaviors, the methods and attributes.
    //This function displaySpecs and displayBrand is from class Smartphones, but can have a different form in this inherited class.
    void displaySpecs(){
        cout << "Year Released: " << m_yearReleased << endl << "iOS Version: " << m_iosVersionOnRelease << endl << "Line Up: " << m_lineUpSeries << endl;
        cout << "Model: " << model << endl << "Network: " << networkTech << endl << "Display: " << displayType << endl << "Chipset: " << chipSet << endl << endl;

    }
};

class Samsung: public Smartphones {
private: 
    int m_yearReleased;
    float m_androidVersionOnRelease;
    string m_lineUpSeries;

public: 
    Samsung(string m, string nt, string dt, string cs, int yearReleased, float androidVersionOnRelease, string lineUpSeries): Smartphones (m, nt, dt, cs) {
        m_yearReleased = yearReleased;
        m_androidVersionOnRelease = androidVersionOnRelease;
        m_lineUpSeries = lineUpSeries;
    }

    void displayBrand(){
        cout << "Brand: Samsung" << endl;
    }

    void displaySpecs(){
        cout << "Year Released: " << m_yearReleased << endl << "Android Version: " << m_androidVersionOnRelease << endl << "Line Up: " << m_lineUpSeries << endl;
        cout << "Model: " << model << endl << "Network: " << networkTech << endl << "Display: " << displayType << endl << "Chipset: " << chipSet << endl << endl;
    }
};


int main (){
    Apple a("Iphone 14 Pro Max", "5G", "OLED", "A16", 2022, 18.0, "14 Series");
    a.displayBrand();
    a.displaySpecs();
    
    cout << endl;
    
    Samsung s("Samsung S25 Ultra", "5G", "OLED", "Snapdragon 8 Elite", 2025, 14.0, "S25 Series");
    s.displayBrand();
    s.displaySpecs();
}