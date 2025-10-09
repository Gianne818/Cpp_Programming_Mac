#include "genTree.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

class MyGenTree : public GenTree{
    int size;
    node* root;
    
    int deleteSubtree(node* n){
        int count = 1;
        for (int i = 0; i<n->numChild; i++){
            if(n->children[i])
            count+=deleteSubtree(n->children[i]);
        }
        delete[] n->children;
        delete n;
        return count;
    }

public:
    MyGenTree(){
        size = 0;
        root = nullptr;
    }

    node* addRoot(int num){
        if(root){
            throw logic_error("Already has root\n");
        }
        root = new node();
        root->elem = num;
        root->parent = nullptr;
        root->children = new node*[10];
        root->numChild = 0;
        size++;
        return root;
    }

    node* addChild(node* parent, int num){
        if(!parent){
            throw invalid_argument("Parent is null \n");
        }
        if(parent->numChild >= 10){
            throw overflow_error("Maximum children reached\n");
        }
        node* child = new node();
        child->elem = num;
        child->parent = parent;
        child->children = new node*[10];
        child->numChild = 0;

        parent->children[parent->numChild++] = child;
        size++;
        return child;
    }

    int remove(node* n){
        if(!n){
            throw logic_error("Node is null.\n");
        }
        if(n==root){
            throw logic_error("Cannot remove root.\n");
        }

        int val = n->elem;
        bool isFound = false;
        //find the node from parent
        if(!n->parent){
            throw logic_error("Node does not exist.\n");
        }
        for (int i = 0; i<n->parent->numChild; i++){
            if(n == n->parent->children[i]){
                //shift left
                for (int j = i; j<n->parent->numChild-1; j++){
                    n->parent->children[j] = n->parent->children[j+1];
                }
                n->parent->numChild--;
                isFound = true;
                break;
            }
        }
        if(!isFound){
            throw logic_error("Node not found.\n");
        }

        //remove subtree
        int countRemoved = deleteSubtree(n);
        size-=countRemoved;
        return countRemoved;

    }

    int getSize(){
        return size;
    }

    node* getRoot(){
        return root;
    }

};

