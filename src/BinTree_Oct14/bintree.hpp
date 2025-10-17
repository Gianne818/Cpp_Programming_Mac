#include "gentree.hpp"
using namespace std;

    // virtual node* addRoot(int) = 0;
    // virtual node* addchild(node*, int) = 0;
    // virtual int remove(node*) = 0;
    // virtual int getSize() = 0;
    // virtual node* getRoot() = 0;

class BinTree : public GenTree {
    int s;
    node* root;

    int deleteSubtree(node* n){
        int count = 1;
        if(n->left){
            count+=deleteSubtree(n->left);
        }
        if(n->right){
            count+=deleteSubtree(n->right);
        }
        delete n;
        return count;
    }

public:
    BinTree(){
        s = 0;
        root = nullptr;
    }

    node* addRoot(int num){
        if(root){
            throw logic_error("Root already exists.");
        }
        node* n = new node();
        n->elem = num;
        root = n;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        s++;
        return n;
    }

    node* addChild(node* parent, int num){
        if(!parent){
            throw logic_error("Parent is null\n");
        }
        node* n = new node();
        n->elem = num;
        n->parent = parent;

        if(!parent->left){
            parent->left = n;
        } 
        else if (!parent->right){
            parent->right = n;
        }
        else {
            throw logic_error("Parent cannot have more children\n");
        }
        s++;
        return n;
    }

    int remove(node* n){
        if(!n){
            throw logic_error("Node is empty\n");
        }
        
        if(n->parent){
            if(n->parent->left==n){
                n->parent->left = nullptr;
            } else if(n->parent->right == n){
                n->parent->right =  nullptr;
            }
        }
         else {
            root = nullptr;
        }

        int count = deleteSubtree(n);
        s-=count;
        return count;
    }
    

    int getSize(){
        return s;
    }

    node* getRoot(){
        if(!root){
            node* tempRoot = new node();
            tempRoot->left = nullptr;
            tempRoot->right= nullptr;
            tempRoot->parent = nullptr;
            return tempRoot;
        }
        return root;
    }

};