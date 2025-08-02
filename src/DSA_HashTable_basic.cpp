#include <iostream>
#include <list>
#include <string>
using namespace std;

//A Hash Table is a data structure that allows fast searching, adding, and deleting of data.
//It is faster than arrays or linked lists as it uses a hash function to directly find the data.
//Particularly useful for large amounts of data.
//A hash function converts a key (like string) into an index.
//Collision happens when two values get the same index.
//Collision handling with Chaining (Using Linked List)
//Some collision handling involve incrementing an index by 1. 
//Example, we can use key (word) to get the value (definition). This is a hash map implementation.
//The example below  is an implementation of a hash table in the form of a hash set 


#define MAX 5
list<string> hashList[MAX]; //an array of lists
//You can think of it as "buckets" where the hashFunction decides which bucket a string belongs to

int hashFunction(string str){
    int sum = 0;
    for (char c: str){ //use char to convert each letter of the string into its ASCII value.
        sum+=int(c);
    }
    return sum % MAX; //uses this as the index for the string
}

void addToList(string str){
    int index = hashFunction(str);
    for (string &i : hashList[index]){
        if(i==str) return; //avoid duplicates
    }
    hashList[index].push_back(str); //add the value to a list in a specified index.
}

//Retrieve an element by its key
bool search(string str){
    int index = hashFunction(str);
    for (string &i : hashList[index]){
        if(i==str) return true; //avoid duplicates
    }
    return false;
}
 //THIS IMPLEMENTATION USES ITERATORS
void deleteData(string str){
    int index = hashFunction(str);
    for (list<string>::iterator it = hashList[index].begin(); it!=hashList[index].end(); it++){
        if(*it==str){
            hashList[index].erase(it);
            cout << str << " has been deleted from the bucket.\n";
            return;
        }
    }
    cout << str << " is not found in the hash table.\n";
}



void containsInWords(string str){
    if(search(str)){
        cout << str << " is contained in bucket: " << hashFunction(str) << endl;
    } else {
        cout << str << " is not in any of the buckets.\n";
    }
}

void display(){
    for (int i = 0; i<MAX; i++){
        cout << "Bucket: " << i <<  " : ";
        if(hashList[i].empty()){
            cout  << "Empty.\n";
        } else {
            for (string &item: hashList[i]){
                cout << item << ", ";
            }
            cout << endl;
        }
    }
}

int main (){
    addToList("car");
    addToList("arc");
    addToList("cat");
    addToList("melon");
    addToList("lemon");
    addToList("tiger");
    addToList("lion");
    addToList("acr");
    addToList("gianne");
    addToList("sami");
    addToList("Saffron");
    addToList("shiro");
    addToList("Blacky");
    addToList("Xenon");

    containsInWords("Xenon");
    containsInWords("gianne");
    containsInWords("sami");
    containsInWords("saffron");

    display();

    cout << endl << endl;

    deleteData("acr");
    deleteData("lion");
    deleteData("tiger");
    deleteData("Melon");
    deleteData("Lemon");
    deleteData("lemon");

    display();
}


