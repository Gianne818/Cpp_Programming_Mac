#include <iostream>
#include <list>
#include <string>
using namespace std;

//A Hash Table is a data structure that allows fast searching, adding, and deleting of data.
//It is faster than arrays or linked lists as it uses a hash function to directly find the data.
//A hash function converts a key (like string) into an index.
//Collision happens when two values get the same index.
//Collision handling with Chaining (Using Linked List)
//Some collision handling involve incrementing an index by 1 

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
/* THIS IMPLEMENTATION USES ITERATORS
void deleteData(string str){
    int index = hashFunction(str); // Find the bucket using the hash function
    // Iterate through the list in the corresponding bucket
    for (auto i = hashList[index].begin(); i != hashList[index].end(); ++i){
        if (*i == str){ // If the element is found
            hashList[index].erase(i); // Erase the element
            cout << str << " has been deleted from bucket " << index << ".\n";
            return;
        }
    }
    cout << str << " not found in the hash table.\n";
}
*/

void deleteData(std::string str) {
    int index = hashFunction(str);
    
    // Remove all instances of str from the list at hashList[index]
    hashList[index].remove(str);
    cout << "Deleted.\n";
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
}


