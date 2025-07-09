#include <iostream>
#include <string>
using namespace std;

//Destructors perform necessary cleanup tasks before an object is destroyed to avoid memory leaks or help prevent the degradation of performance and stability
//It is a special function invoked when an object is being destroyed
//It is the opposite of a constructor. 
//Constructor is to allocate, destructor is to deallocate

class Book {
private:
    string m_title, m_author;
    int* m_rates;
    int m_numRates;

public:
    Book (string title, string author){
        m_title = title;
        m_author = author;

        m_numRates = 2;
        m_rates = new int[m_numRates];
        m_rates[0] = 1;
        m_rates[1] = 2;

        cout << title << " Constructor invoked.\n";
    }

    //Destructors always start with ~ and must not receive a parameter
    //Only one destructor per class
    //The compiler will automatically deallocate memory for as long as there are no pointers.
    //If you use pointers, then thats when you should use destructors
    ~Book (){
        delete[] m_rates;
        m_rates = nullptr; 
        //It is good practice to set to nullptr, to indicate that it does not point to any valid address.
        //when we used delete[], the memory occupied by the objects are freed, but the pointer itself still holds the address of that memory location
        cout << m_title << "Destructor invoked." << endl;
    }
};

int main (){
    Book b1 ("Hatdog", "Gianne");
    Book b2 ("Harry Potter", "J.K. Rowling");
}