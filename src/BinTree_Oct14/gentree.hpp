#include "node.hpp"
#include <iostream>
using namespace std;

class GenTree {
    public:
    virtual node* addRoot(int) = 0;
    virtual node* addChild(node*, int) = 0;
    virtual int remove(node*) = 0;
    virtual int getSize() = 0;
    virtual node* getRoot() = 0;

    void print(){
        cout << "Size: " << getSize() << endl;
        if(getSize()==0){
            cout << "Empty\n";
            return;
        }
        printNode("", getRoot(), false);
    }

    private:
    void printNode(string prefix, node* n, bool isLeft) {
        if(!n) return;
        cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: ");
        cout << n->elem << endl;

        printNode(prefix + "|   ", n->left, true);
        printNode(prefix + "|   ", n->right, false);
    }

};