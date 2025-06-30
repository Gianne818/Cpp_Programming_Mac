#include <iostream>
#include <string>
using namespace std;

//encapsulation is mainly to prevent accidental modification of data, hence using private data but public methods.

class Employee {
    private:
        string name;
        string ID;
        float salary;
    
    public:
        Employee (string empName, string empID, float empSalary){
            name = empName;
            ID = empID;
            salary = empSalary;
        }

        Employee (){
            name = "unknown";
            ID = "unknown";
            salary = 0.0;
        }

        //setter
        void setEmployeeDetails(){
            string eName;
            string eID;
            float eSalary;

            cout << "Enter employee name: ";
            cin >> eName;

            cout << "Enter employee ID: ";
            cin>> eID;

            cout << "Enter monthly salary: ";
            cin >> eSalary;

            name = eName;
            ID = eID;
            salary = eSalary;
        }
        
        //using a "friend" function can make it so that a function that is non-member of a class can access private members.
        friend void displayEmployeeDetails(Employee emp);

        // void displayEmployeeDetails(){
        //     cout << "ID: " << ID << endl << "Name: " << name << endl << "Salary: " << salary << endl << endl;
        // }
        
        
};

void displayEmployeeDetails(Employee emp){
            cout << "ID: " << emp.ID << endl << "Name: " << emp.name << endl << "Salary: " << emp.salary << endl << endl;
}

int main (){
    Employee emp1 ("John", "24-0920-213", 35000.5);
    Employee emp2 ("Jean", "24-6052-978", 40000.8);
    Employee emp3;

    // cout << "Enter employee name: ";
    // cin >> emp3.name;
    //Above code will not work, because "name" is a private variable. We can use setter.

    emp3.setEmployeeDetails();

    // emp1.displayEmployeeDetails();
    // emp2.displayEmployeeDetails();
    // emp3.displayEmployeeDetails();

    displayEmployeeDetails(emp1);
    displayEmployeeDetails(emp2);
    displayEmployeeDetails(emp3);

}