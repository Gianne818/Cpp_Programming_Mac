#include <iostream>
#include <vector>
//#include <iterator> include this if you want to use advanced iterator functions like advance(), distance()...
using namespace std;

//Iterators are used to access and iterate through elements of data structures such as vectors, sets, maps, lists, etc.
//Each STL container classes have their own specific iterator types defined as nested classes.
//The most obvious form of iterator is a pointer. But other forms of iterators exists.

//begin() returns an iterator pointing to the first element of the container.
//end() returns an iterator pointing after the last element, one element after the container's last item.
//rbegin() and .rend() can be used to iterate in reverse order.
//cbegin() and cend(), as well as crbegin() and crend() returns a constant iterator, useful when you dont want to manipulate values pointed to by the iterator object.
//both front() & back() returns a reference to thew first and last element, so you cannot use it for iterating.

//Iterators are often used with different algorithm functions such as sort() and find() found in the <algorithm> library
//range-based for loop uses begin() and end() to obtain iterators

int main (){
    vector<int> numbers = {1, 2, 3, 4, 5};

    cout << "\nIterators:\n";
    for (vector<int>::iterator it = numbers.begin(); it!=numbers.end(); it++){ //can be replaced with keyword auto
        cout << *it << endl; //need to dereference it
    } 

    cout << "\nRange based:\n";
    for (int nums : numbers){
        cout << nums << endl;
    }
}