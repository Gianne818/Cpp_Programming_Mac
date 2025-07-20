#include <iostream>
#include <vector>
using namespace std;

//Data structures are used to store and organize data.
//It is a collection of organized data, it speeds up the process of accessing our data
//Arrays, lists, vectors, stack, queue, deque, set, map, are some of the common data structs
//They are in the STL library, which consists of data structures and algorithms to effectively store and manipulate data
//OTther common data structures are arrays, linked lists, stacks & queues, hash tables, trees, graphs

int main (){
    //just an exampleof using a data structure
    vector<string> animals = {"Bird", "Dog", "Cat"};
    for (string animal: animals){
        cout << animal << endl;
    }
}

//Key Components of STL
//Containers - data structure providing a way to store data (e.g. vectors, lists).
//Iterators - objects used to access elements of ds
//Algorithms - functions like sort() or find(), that perform operations on daa structures through iterators
//Function Objects (Functors) - basically a custom algorithm implementation