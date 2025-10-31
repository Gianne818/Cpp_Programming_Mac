#include "node.hpp"
#include <iostream>
using namespace std;

class GenTree {
public:
    virtual node* left(node*) = 0;
    virtual node* right(node*) = 0;
    virtual node* addRoot(int e) = 0;
    virtual node* insert(int, node*) = 0;
    virtual node* getRoot() = 0;
    virtual int getSize() = 0;
    virtual void  preOrder(node*) = 0;
    virtual void  inOrder(node*) = 0;
    virtual void  postOrder(node*) = 0;
    virtual void breadthFirst() = 0;
    virtual node* findNode(int, node*) = 0;
   // virtual int removeNodeOnly(int num) = 0;
    virtual int remove(int num) = 0;

    void print(){
        cout << "Size: " << getSize() << endl;
        if(getSize()==0){
            cout << "Empty.\n";
            return;
        }
        printNode("", getRoot(), false);
    }

private:
    void printNode(string prefix, node* n, bool isLeft){
        if(!n) return;
        cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: ");
        cout << n->elem << endl;

        printNode(prefix + "|   ", n->left, true);
        printNode(prefix + "|   ", n->right, false);
    }
};