#include <string>
using namespace std;

struct Entry {
    int score;  
    string name;
};

class List {
    virtual void add(Entry*) = 0;
    virtual void print() = 0;
    virtual Entry* remove(string name) = 0;
    virtual Entry get(int pos) = 0;
};