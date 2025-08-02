#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

//Hash set is a form of hash table data structure that usually holds a large number of data without associated values
//Allows fast search, insertion, and deletion, making it ideal for tasts like lookup operations to check if an element is part of a set.
//In hash sets, no duplicate values are allowed.

//Hash set is a hash table where only keys exists, and their value is implicitly true(exists).
//Examples in C++ STL is <unordered_set> and <set>

//The preevious file DSA_HashTable_basic.cpp implements a hash set form.
//This is another example of a Hash Set implementation.

class HashSet{
    vector<list<string>> buckets; //dynamic size of number of buckets for object of HashSet.
    int size;

public:
    HashSet (int size) : size(size), buckets(size){}

    int hashFunction(string str);
    void addToBucket(string str);
    bool search(string str);
    void containsInWords(string str);
    void display();
    void deleteData(string str);
};

int HashSet::hashFunction(string str){
    int sum = 0;
    for (char c : str){
        sum+=(int)c;
    }
    return sum%size;
}

void HashSet::addToBucket(string str){
    int ind = hashFunction(str);
    //Avoid duplicates
    for (string &i : buckets[ind]){
        if(i==str) {
            cout << str << " already in the hash set.\n";
            return;
        }
    }
    buckets[ind].push_back(str);
    cout << "Successfully added: " << str << endl;
}

bool HashSet::search(string str){
    int ind = hashFunction(str);
    for (string &i : buckets[ind]){
        if(i==str) return true;
    }
    return false;
}

void HashSet::containsInWords(string str){
    if(search(str)){
        cout << str << " is in bucket " << hashFunction(str) << endl; 
    } else {
        cout << str << " is not in any buckets.\n";
    }
}

void HashSet::display(){
    for (int i = 0; i<size; i++){
        cout << "Bucket " << i << ": ";
        for(string &i : buckets[i]){
            cout << i << ", ";
        }
        cout << endl;
    }
}

void HashSet::deleteData(string str){
    int ind = hashFunction(str);
    for (auto it = buckets[ind].begin(); it!=buckets[ind].end(); it++){
        if(*it == str){
            buckets[ind].erase(it);
            cout << str << " successfully deleted.\n";
            return;
        }
    }
    cout << str << " is not found in any of the buckets.\n";
}

int main (){
    HashSet h1(10);

    while(1){
        cout << endl << "-----------------------";
        cout << "\nWhat do you want to do?\n";
        int num;
        cout << "1. Add Data\n" << "2. Search\n" << "3. Delete Data\n" << "4. Display Current Set\n" << "5. Exit" << endl;
        cin >> num;
        string key;
        switch(num){
            case 1: 
                cout << "Enter string to add: ";
                cin >> key;
                h1.addToBucket(key);
                break;

            case 2: 
                cout << "Enter string to search: ";
                cin >> key;
                h1.containsInWords(key);
                break;

            case 3: 
                cout << "Enter string to delete ";
                cin >> key;
                h1.deleteData(key);
                break;

            case 4: 
                h1.display();
                break;

            case 5: 
                return 0;
            
            default: 
                cout << "Invalid input. Enter numbers 1 to 5.\n";
                break;
        }

    }
}