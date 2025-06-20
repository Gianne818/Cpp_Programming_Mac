#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct person {
    string name;
    int age;
    float weight;
    float height;
    float bmi;
};

int main (){
    int s;
    cout << "Enter the number of person/s: ";
    cout << fixed << setprecision(2);
    cin >> s;
    person p[s];
    for (int i = 0; i<s; i++){
        cout << "Enter details for person " << i+1 << ":\n";
        cout << "Name: ";
        cin >> p[i].name;

        cout << "Age: ";
        cin >> p[i].age;

        cout << "Weight: ";
        cin >> p[i].weight;

        cout << "Height: ";
        cin >> p[i].height;

        cout << endl;
    }

    for (int i=0; i<s; i++){
        cout << "BMI for " << p[i].name << ": " << p[i].weight/(p[i].height*p[i].height) << endl;
    }

}

