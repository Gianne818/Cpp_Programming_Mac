#include "binarytree.hpp"
#include <iostream>
#include <queue>
using namespace std;

/*
    virtual node* left(node*) = 0;
	virtual node* right(node*) = 0;
	virtual node* addRoot(int e) = 0;
	virtual node* addLeft(node* p, int e) = 0;
	virtual node* addRight(node* p, int e) = 0;
	virtual int remove(node* n) = 0;
	virtual node* getRoot() = 0;
	virtual void print() = 0;

	virtual node* sibling(node* n) = 0;
*/

class MyBinaryTree : public BinaryTree {
    node* root;
    int size;

public:
    MyBinaryTree(){
        root = nullptr;
        size = 0;
    }


    node* findNode(int num, node* n){
        if(!n) return nullptr;
        if(n && n->elem == num){
            return n;
        }
        
        node* leftRes = findNode(num, n->left);
        if(leftRes) return leftRes;
        return findNode(num, n->right);
    }

    node* left(node* n){
        if(!n){
            return nullptr;
        } else if (!n->left){
            return nullptr;
        } 
        return n->left;
    }

    node* right(node* n){
        if(!n){
            return nullptr;
        } else if (!n->right){
            return nullptr;
        } else {
            return n->right;
        }
    }

    node* addRoot(int num){
        if(root){
            return nullptr;
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
            return nullptr;
        } else if(p->left){
            return nullptr;
        } else {
            node* temp = findNode(num, root);
            if(temp && temp->elem==num){
                return nullptr;
            }
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
            return nullptr;
        } else if(p->right){
            return nullptr;
        } else {
            node* temp = findNode(num, root);
            if(temp && temp->elem==num){
                return nullptr;
            }
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

    void breadthFirst(){
        queue<node*> q;
        if(!getRoot())return;
        q.push(getRoot());

        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            cout << temp->elem << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            
        }
    }

    int remove(node* n){
        if(!n){
            return -1;
        }
        if(n->right && n->left){
            return -1;
        }

        int val = n->elem;

        //check if n is root
        if(n==root){
            if(!n->right && !n->left){
                root = nullptr;
            }

            //if root has right child
            else if(n->right){
                root = n->right;
                root->parent = nullptr;
            }

            //if root has left child
            else if(n->left){
                root = n->left;
                root->parent = nullptr;
            }

            size--;
            free(n);
            return val;
        }
        
        //if node has right child
        else if(n->right){
            n->right->parent = n->parent;
            if(n == n->parent->right){
                n->parent->right = n->right;
            } else n->parent->left = n->right;
        }

        //if node has left child
        else if(n->left){
            n->left->parent = n->parent;
            if(n == n->parent->left){
                n->parent->left = n->left;
            } else n->parent->right= n->left;
        }

        //if n has no children
        else {
            //if n is right child of its parent
            if(n == n->parent->right){
                n->parent->right = nullptr;
            } else {
                n->parent->left = nullptr;
            }
        } 

        size--;
        free(n);
        return val;
    }

    node* sibling(node* n){
        if(!n || !n->parent) return nullptr;
        if(n == n->parent->right){
            return n->parent->left;
        } else {
            return n->parent->right;
        }
    }

    void print(){
        cout << "Size: " << getSize() << endl;
        if(getSize()==0){
            cout << "Empty.\n";
            return;
        }
        printNode("", getRoot(), false);
    }

    void printNode(string prefix, node* n, bool isLeft){
        if(!n) return;
        cout << prefix;
        cout << (isLeft ? "+--L: " : "+--R: ");
        cout << n->elem << endl;

        printNode(prefix + "|   ", n->left, true);
        printNode(prefix + "|   ", n->right, false);
    }



// 12 10 14 9 11 13 15
};