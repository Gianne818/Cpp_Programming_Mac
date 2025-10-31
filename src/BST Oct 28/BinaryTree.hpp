#include "GenTree.hpp"
#include <iostream>
#include <queue>
using namespace std;


class BinTree : public GenTree {
    node* root;
    int size;

    node* create_node(int num, node* parent){
        node* n = new node();
        n->elem = num;
        n->parent = parent;
        size++;
        return n;
    }

public:
    BinTree(){
        root = nullptr;
        size = 0;
    }


    // node* findNode(int num, node* n){
    //     if(!n) return nullptr;
    //     if(n && n->elem == num){
    //         return n;
    //     }
        
    //     node* leftRes = findNode(num, n->left);
    //     if(leftRes) return leftRes;
    //     return findNode(num, n->right);
    // }

    node* findNode(int num, node* n){
        if(!n) return nullptr;

        if(n && n->elem == num){
            return n;
        }
        return (num < n->elem) ? findNode(num, n->left) : findNode(num, n->right);
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

    node* insert(int num, node* n){
        //if root does not exist, create root and return it.
        if(!root){
            root = create_node(num, nullptr);
            return root;
        }

        if(num < n->elem){
            //while n->left still exists, proceed to the left. if it doesnt, create node with n as parent
            n->left ? insert(num, n->left) : n->left = create_node(num, n);
        } 
        else if (num > n->elem){
            //while n->right still exists, proceed to the right. if it doesnt, create node with n as parent
            n->right ? insert(num, n->right) : n->right = create_node(num, n);
        }
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

    int remove(int num){
        node* n = findNode(num, root);
        if(!n) throw logic_error("Node not found.\n");

        int val = n->elem;

        if(n == root){
            cout << "Triggered condition for root\n";
            //if no child
            if(!n->right && !n->left){
                root = nullptr;
            }
            
            //if one child
            else if(n->left && !n->right){
                cout << "Triggered n->left\n";
                root = n->left;
            }
            else if (n->right && !n->left){
                cout << "Triggered n->right\n";
                root = n->right;
            }

            //if two children
            else {
                cout << "Triggered else block\n";
                node* temp = n->right;
                while(temp->left){
                    temp = temp->left;
                }
                root->elem = temp->elem;
                if(temp->right) 
                    temp->right->parent = temp->parent; //leftmost child has right child
                if(temp == temp->parent->right) 
                    temp->parent->right = temp->right; //if temp is a right child (it is the leftmost yet is the parent's right)
                else 
                    temp->parent->left = temp->right;
                delete(temp);
                size--;
                return val;
            }
            size--;
            return val;
         }

         //if no child
        if(!n->right && !n->left){
            if(n == n->parent->left) n->parent->left = nullptr;
            else n->parent->right = nullptr;
        }

        else {
            cout << "Triggered else block\n";
                node* temp = n->right;
                while(temp->left){
                    temp = temp->left;
                }
                n->elem = temp->elem;
                if(temp->right) 
                    temp->right->parent = temp->parent; //leftmost child has right child
                if(temp == temp->parent->right) 
                    temp->parent->right = temp->right; //if temp is a right child (it is the leftmost yet is the parent's right)
                else 
                    temp->parent->left = temp->right;
                delete(temp);
                size--;
                return val;
        }
        delete n;
        size--;
        return val;
    }

    // int removeNodeOnly(int num){
    //     node* n = findNode(num, root);
    //     if(!n){
    //         throw logic_error("Node not found.\n");
    //     }
    //     if(n->right && n->left){
    //         throw logic_error("Cannot remove " + to_string(n->elem) + " as it has 2 children\n");
    //     }

    //     int val = n->elem;

    //     //check if n is root
    //     if(n==root){
    //         if(!n->right && !n->left){
    //             root = nullptr;
    //         }

    //         //if root has right child
    //         else if(n->right){
    //             root = n->right;
    //             root->parent = nullptr;
    //         }

    //         //if root has left child
    //         else if(n->left){
    //             root = n->left;
    //             root->parent = nullptr;
    //         }

    //         size--;
    //         free(n);
    //         return val;
    //     }
        
    //     //if node has right child
    //     else if(n->right){
    //         n->right->parent = n->parent;
    //         if(n == n->parent->right){
    //             n->parent->right = n->right;
    //         } else n->parent->left = n->right;
    //     }

    //     //if node has left child
    //     else if(n->left){
    //         n->left->parent = n->parent;
    //         if(n == n->parent->left){
    //             n->parent->left = n->left;
    //         } else n->parent->right= n->left;
    //     }

    //     //if n has no children
    //     else {
    //         //if n is right child of its parent
    //         if(n == n->parent->right){
    //             n->parent->right = nullptr;
    //         } else {
    //             n->parent->left = nullptr;
    //         }
    //     } 

    //     size--;
    //     free(n);
    //     return val;
    // }

    int removeNodeAndSubtree(int num){
        return -1;
    }




// 12 10 14 9 11 13 15
};