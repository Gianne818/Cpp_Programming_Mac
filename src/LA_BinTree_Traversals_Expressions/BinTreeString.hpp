#include "nodeString.hpp"
#include <iostream>
#include <queue>
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

class BinTree {
    node* root;
    int size;

public:
    BinTree(){
        root = nullptr;
        size = 0;
    }


    void setRoot(node* n){
        root = n;
        size++;
    }

    node* findNode(string str, node* n){
        if(!n) return nullptr;
        if(n && n->elem == str){
            return n;
        }
        
        node* leftRes = findNode(str, n->left);
        if(leftRes) return leftRes;
        return findNode(str, n->right);
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
            throw logic_error("No right child.\n");
        } else {
            return n->right;
        }
    }

    node* addRoot(string str){
        if(root){
            throw logic_error("Root already exists.\n");
        }

        node* n = new node();
        n->parent = nullptr;
        n->elem = str;
        n->right = nullptr;
        n->left = nullptr;
        root = n;
        size++;
        return n;
    }

    node* addLeft(node* p, string str){
        if(!p){
            throw logic_error("Parent does not exist.\n");
        } else if(p->left){
            throw logic_error("Already has left child\n");
        } else {
            node* temp = findNode(str, root);
            if(temp && temp->elem==str){
                throw logic_error("Value already exists.\n");
            }
        }

        node* n = new node();
        n->elem = str;
        n->parent = p;
        n->left = nullptr;
        n->right = nullptr;
        p->left = n;
        size++;
        return n;
    }

    node* addRight(node* p, string str){
        if(!p){
            throw logic_error("Parent does not exist.\n");
        } else if(p->right){
            throw logic_error("Already has right child\n");
        } else {
            node* temp = findNode(str, root);
            if(temp && temp->elem==str){
                throw logic_error("Value already exists.\n");
            }
        }
        
        
        node* n = new node();
        n->elem = str;
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

    int evaluate(){
        if(!root) throw logic_error("No root.");
        return evaluateHelper(root);
    }

    int evaluateHelper(node* n){
        if(!n) return 0;
        
        if(!n->left && !n->right){
            return stoi(n->elem);
        }

        int leftVal = evaluateHelper(n->left);
        int rightVal = evaluateHelper(n->right);
        string op = n->elem;

        if(op=="+") return leftVal + rightVal;
        if(op=="-") return leftVal - rightVal;
        if(op=="*") return leftVal * rightVal;
        if(op=="/") return leftVal / rightVal;

        throw logic_error("Invalid operator\n");

    }

// 12 10 14 9 11 13 15
};