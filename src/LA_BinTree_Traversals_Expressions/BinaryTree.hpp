#include "GenTree.hpp"
#include <iostream>
using namespace std;

/*
    virtual node* left(node*) = 0;
    virtual node* right(node*) = 0;
    virtual node* addRoot(int e) = 0;
    virtual node* addLeft(node* p, int e) = 0;
    virtual node* addRight(node* p, int e) = 0;
    virtual node* getRoot() = 0;
    virtual void print() = 0;
    virtual void  preOrder(node*) = 0;
    virtual void  inOrder(node*) = 0;
    virtual void  postOrder(node*) = 0;
*/

class BinTree : public GenTree {
    node* root;
    int size;

public:
    BinTree(){
        root = nullptr;
        // root->left = nullptr;
        // root->right = nullptr;
        // root->parent = nullptr;
        size = 0;
    }


    node* findNode(int num, node* n){
        if(n && n->elem == num){
            return n;
        }
        if(!n) return nullptr;
        return findNode(num, n->left);
        return findNode(num, n->right);
    }

    node* left(node* n){
        if(!n){
            throw logic_error("Node is null.\n");
        } else if (!n->left){;
            throw logic_error("No left child.\n");
        } 
        return n->left;
    }

    node* right(node* n){
        if(!n){
            throw logic_error("Node is null.\n");
        } else if (!n->right){;
            throw logic_error("No left child.\n");
        } else {
            return n->right;
        }
    }

    node* addRoot(int num){
        if(root){
            throw logic_error("Root already exists.\n");
        }

        node* n = new node();
        n->parent = nullptr;
        n->elem = num;
        n->right = nullptr;
        n->left = nullptr;
        root = n;
        size++;
        return n;
    }

    node* addLeft(node* p, int num){
        if(!p){
            throw logic_error("Parent does not exist.\n");
        } else if(p->left){
            throw logic_error("Already has left child\n");
        }

        node* n = new node();
        n->elem = num;
        n->parent = p;
        n->left = nullptr;
        n->right = nullptr;
        p->left = n;
        size++;
        return n;
    }

    node* addRight(node* p, int num){
        if(!p){
            throw logic_error("Parent does not exist.\n");
        } else if(p->right){
            throw logic_error("Already has right child\n");
        }

        node* n = new node();
        n->elem = num;
        n->parent = p;
        n->left = nullptr;
        n->right = nullptr;
        p->right = n;
        size++;
        return n;
    }

    node* getRoot(){
        return root;
    }

    int getSize(){
        return size;
    }


    void preOrder(node* n){
        if(!n) return;
        cout << n->elem << " ";
        preOrder(n->left);
        preOrder(n->right);
    }

    void inOrder(node* n){
        if(!n) return;
        inOrder(n->left);
        cout << n->elem << " ";
        inOrder(n->right);
    }

    void postOrder(node* n){
        if(!n) return;
        postOrder(n->left);
        postOrder(n->right);
        cout << n->elem << " ";
    }
};