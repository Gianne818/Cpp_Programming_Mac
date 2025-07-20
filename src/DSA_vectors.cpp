#include <iostream>
#include <string>
#include <vector> //include the header file
using namespace std;

//A vector in c++ is like a resizeable array
//There is no direct quivalent to realloc in c++, as c++ focuses on OO principles with better memory management
//Vectors can resize and automatically manage its memory as it is abstracted, so no need to free it manually

//syntax
//Constructor/Destructor - vector<data_type> name (numberOfElements, valueToInitialize);
//Initializer List Constructor - vector<data_type> name = {value} - usual array initialization



int main (){
    vector <string> animals = {"Bird", "Dog", "Cat"};
    vector <int> number(5, 1); //number = {1, 1, 1, 1, 1,};

    

}

    //.front() - first elem
    //.back() - last elem
    //.at(index) - get elem at specified index
    //data[index] = "new value" - change value at specified index
    //.push_back(data) - add elem at the end
    //.pop_back() - delete last element
    //.size() - returns the number of elements of a vector
    //.empty() - returns 1 if vector is empty, 0 otherwise
    //.resize(newSize, valueToInitialize) - resize the array and init a new value if more than current size
    //.reserve(numElem) - reserves space for atleast numElem amount of elements
    //.shrink_to_fit() - reduce vector capacity to match the size
    //.insert(iteratorPosition, value) - insert an element of a specified value to a specified index
    //.erase(iteratorPosition) - remove element at specified position
    //.clear() - remove all elements
    //.swap(vectorToSwapValuesWith) - exchanges values with another vector
    //.assign(values) - assign new values to a vector
    //.emplace_back(data) - DIRECTLY constructs a NEW object at the end of the vector


    //Elems are usually only added and removed from the end of the vector. 
    //In that case, it is better to use deque instead of vector
    //push_back() is best used when you already have the object you want to add to the vector
    //emplace_back() is best used when constructing objects directly at the end of the vector, commonly used for user-defined types
    