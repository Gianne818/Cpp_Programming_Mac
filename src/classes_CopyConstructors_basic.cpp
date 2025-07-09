#include <iostream>
#include <string>
using namespace std;

//Copy constructors is used to create an object based on an already existing object
//The compiler also has default copy constructor
//But if you use pointers, then it is necessary to provide your own copy constructor

class Book {
public:
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

    
    ~Book (){
        delete[] m_rates;
        m_rates = nullptr; 
        cout << m_title << " Destructor invoked." << endl;
    }

	//Copy constructors have one parameter –– the class it belongs to
	//You need to pass by reference(&), because you need a copy constructor to copy, and without "&", you're just creating a copy of the object to make the copy constructor, which youd need a copy constructor for.
	//Basically a recursive call to the copy constructor
	                                       
	Book(const Book &orig){ //use const to avoid modifying the original
		m_title = orig.m_title;
		m_author = orig.m_author;
		//m_rates = orig.m_rates; since m_rates is a dynamic array, if we copy it like this, it just copies the value address of the array from the original. When original is deleted, there is nothing left to delete for the copy.
		m_numRates = orig.m_numRates;

		m_rates = new int[m_numRates];
		for (int i = 0; i<m_numRates; i++){
			m_rates[i] = orig.m_rates[i];
		}
	}
};

//The second use of a copy constructor is when the compiler creates a temporary object, like in this function (since its passed as value), and the third is when returning the object by value
void displayBook(Book b){
	cout << "Title: " << b.m_title << endl;
	cout << "Author: " << b.m_author << endl;

	int sum = 0;
	for (int i = 0; i<b.m_numRates; i++){
		sum+=b.m_rates[i];
	}

	cout << "Average Rate: " << sum/b.m_numRates << endl << endl;
}

int main (){
    Book b1 ("Hatdog", "Gianne");
    Book b2 ("Harry Potter", "J.K. Rowling");

	Book b3(b2);
	Book b4 = b1; //This is valid and is not an assigment operator, it is still invoking copy constructor.
	//Whenever a new object is created based on an existing object, you are invoking copy constructor.
	//Assignment operators will be invoked when you are trying to reassign new values of an already existing object.
	//Example:
	//b3 = b1; //This is invoking an assignment operator.
	//Book& operator=(const Book &orig) {...} something like that. More on this later

	displayBook(b1);
	displayBook(b2);
	displayBook(b3);
	displayBook(b4);
}