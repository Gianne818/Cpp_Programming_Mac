#include <cstdlib>
#include <iostream>
#include "binarytree.hpp"
using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int size;

	
	node* create_node(int e, node* parent) {
	    // TODO this helper method
	    node* n = new node();
	    n->elem = e;
	    n->parent = parent;
	    n->left = n->right = nullptr;
	    return n;
	}

	public:
	node* left(node* n) {
	    return n->left;
	}

	node* right(node* n) {
	   return n->right;
	}
	
	node* sibling(node* n){
	    if(!n->parent) return nullptr;
	    
	    if(n == n->parent->left){
	        return right(n->parent);
	    }
		else if(n == n->parent->right){
	       return left(n->parent);
	    }

	}

	MyBinaryTree(){
	    root = nullptr;
	    size = 0;
	}
	node* addRoot(int e) {
        if(root) throw logic_error("Already has root");
        root = create_node(e, nullptr);
        size++;
		return root;
	}

	node* addLeft(node* p, int e) {
        if(p->left) throw logic_error(to_string(p->elem) + " already has left child");
        node* n = create_node(e, p);
        p->left = n;
        size++;
		return n;
	}

	node* addRight(node* p, int e) {
        if(p->right) throw logic_error(to_string(p->elem) + " already has right child");
        node* n = create_node(e, p);
        p->right = n;
        size++;
		return n;
	}
	
	int remove(node* n){
	    if(n->left && n->right) throw logic_error("Cannot remove " + to_string(n->elem) + " for it has 2 children");
	    
	    int val = n->elem;
	    if(n == root){
	        if(!n->left && !n->right){
	            root = nullptr;
	            size--;
	            return val;
	        }
	        
	        if(n->left){
	           // if(n->parent->left == n) n->parent->left = n->left;
	           // if(n->parent->right == n) n->parent->right = n->left;
	           root = n->left;
	        }
	        
	        if(n->right){
	           // if(n->parent->left == n) n->parent->left = n->right;
	           // if(n->parent->right == n) n->parent->right = n->right;
	           root = n->right;
	        }
	        root->parent = nullptr;
	        size--;
	        return val;
	    }
	    
	    
	    if(n->left){
            if(n->parent->left == n){
                n->left->parent = n->parent;
                n->parent->left = n->left;
            } 
            if(n->parent->right == n){
                n->left->parent = n->parent;
                n->parent->right = n->left;
            } 
        }
        
        if(n->right){
            if(n->parent->left == n){
                n->right->parent = n->parent;
                n->parent->left = n->right;
            } 
            if(n->parent->right == n){
                n->right->parent = n->parent;
                n->parent->right = n->right;
            } 
        }
        
        else {
            if(n == n->parent->right) n->parent->right = nullptr;
            if(n == n->parent->left) n->parent->left = nullptr;
            n = nullptr;
        }
        
        size--;
        return val;
	}

    int getSize() {
        return size;
    }

	node* getRoot() {
		return root;
	}
};

