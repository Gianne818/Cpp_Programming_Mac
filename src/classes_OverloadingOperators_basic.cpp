#include <iostream>
#include <string>
using namespace std;


//Overloading operators is useful when performing operations on user-defined data types.
//The compiler knows what to do when using + to add integers, but it does not know what to do with those operators when performed with classes.
//To do an overloading, use the operator keyword, followed by the operator to be overloaded
class Book {
protected: 
    string title, Author;
    int PageNumber;
    int* pageID;

public:
    //"This" -  simply put, refers to the current object. 
    //In the example, "this" refers to the title of the class object, and not the parameter given in the constructor.
    Book (string title, string author, const int pageNumber){
        this->title = title;
        this->Author = author;
        this->PageNumber = pageNumber;

        pageID = new int[PageNumber];
        for (int i = 0; i<pageNumber; i++){
            pageID[i] = 1000+i;
        }
    }

    //Compiler provides default assignment oeprator, but you need to provide your own when involving dynamic arrays
    Book& operator=(const Book& orig){
        this->title = orig.title;
        this->Author = orig.Author;
        this->PageNumber = orig.PageNumber;

        pageID = new int[PageNumber];
        for (int i = 0; i<PageNumber; i++){
            pageID[i] = 1000+i;
        }

        return* this;
    } //The return type of this function is a reference to the current object,
    // as it is invoked by an existing object whose values are replaced with new values

    ~Book (){
        delete[] pageID;
        pageID = nullptr;
    }

    friend ostream& operator<<(ostream& Cout, Book& myBook);

    
};


//it is standard practice to pass by reference, since an instance of an object is created whenever this function is called, which is inefficient.
ostream& operator<<(ostream& Cout, Book& myBook){
    Cout << "Author: " << myBook.Author << endl;
    Cout << "Title: " << myBook.title << endl;
    Cout << "Number of Pages Identified: " << myBook.PageNumber << endl;
    Cout << "Page IDs: ";
    for (int i = 0; i<myBook.PageNumber; i++){
        Cout << myBook.pageID[i] << " ";
    }
    Cout << endl << endl;
    return Cout; //return Cout to be able to be able to chain output streams
} //The return type of this function is a reference to the ostream object, in this case, Cout.
//ostream –– class; cout –– object of ostream; << –– insertion operator used in output streams.


int main (){
    Book b1("Harry Potter", "J.K. Rowling", 5);
    Book b2("Trials of Apollo", "Rick Riordan", 7);
    b1 = b2;
    
    //operator<<(cout, b1); can also call it as a function, but less common. You cannot directly chain output this way since we did not use <<.

    cout << b1 << b2;
}