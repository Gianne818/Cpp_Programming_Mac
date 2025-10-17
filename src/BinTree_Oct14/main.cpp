#include "bintree.hpp"
#include <iostream>
using namespace std;

int main (){
    GenTree* tree = new BinTree();
    try{
        tree->addRoot(1);
        tree->addChild(tree->getRoot(), 2);
        tree->addChild(tree->getRoot(), 3);
        tree->addChild(tree->getRoot()->left, 4);
        tree->addChild(tree->getRoot()->left, 5);
        tree->addChild(tree->getRoot()->right, 6);
        tree->addChild(tree->getRoot()->right, 7);
        cout << "Number of removed elements: " << tree->remove(tree->getRoot()) << endl;
        cout << "Number of removed elements: " << tree->remove(tree->getRoot()->left) << endl;
        cout << "Number of removed elements: " << tree->remove(tree->getRoot()->right) << endl;

    } catch(exception& e){
        cout << e.what();
    }
    tree->print();
    
    
}