#include "myGenTree.hpp"
#include <iostream>
using namespace std;

int main (){
    GenTree* tree = new MyGenTree();
    try{
        node* thirteen = tree->addRoot(13);
        //node* seven = tree->addRoot(7);
        tree->addChild(thirteen, 20);
        tree->addChild(thirteen, 10);   
        tree->addChild(thirteen, 16);
        tree->addChild(thirteen->children[0], 21);
        tree->addChild(thirteen->children[0], 22);
        tree->addChild(thirteen->children[0], 23);
        tree->addChild(thirteen->children[1], 11);
        tree->addChild(thirteen->children[1], 12);
        tree->addChild(thirteen->children[1], 13);
        tree->addChild(thirteen->children[1]->children[0], 14);
        tree->addChild(thirteen->children[1]->children[0], 15);
        tree->addChild(thirteen->children[1]->children[0], 16);
        cout << "Number of children removed: " << tree->remove(thirteen->children[0]) << endl;
        cout << "Number of children removed: " << tree->remove(thirteen->children[1]) << endl;
        cout << "Number of children removed: " << tree->remove(thirteen->children[1]) << endl;

    } catch(exception& e){
        cout << e.what();
    }
    tree->print();
    
    
}