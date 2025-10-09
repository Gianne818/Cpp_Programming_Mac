#include "node.hpp"
#include <iostream>
using namespace std;

class GenTree{
public:
    virtual node* addRoot(int) = 0;
    virtual node* addChild(node*, int) = 0;
    virtual int remove(node*) = 0;
    virtual int getSize() = 0;
    virtual node* getRoot() = 0;

    void print(){
        cout << "Size: " << getSize() << endl;
        if(!getRoot()){
            cout << "Empty\n";
            return;
        }
        printNode("", getRoot());
    }

private:
    void printNode(string prefix, node* n){
        cout << prefix << "+-->: " << n->elem << endl;
        for (int i = 0; i<n->numChild; i++){
            printNode(prefix + "|   ", n->children[i]);
        }
    }


};