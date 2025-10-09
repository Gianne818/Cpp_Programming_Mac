
#include "gentree.hpp"
#include <stdexcept>
using namespace std;

class MyGenTree : public GenTree {
    int size;
    node* root;
    
public:
    MyGenTree(){
        size = 0;
        root = nullptr;
    }
    
    node* addRoot(int num){
        if(root){
            throw logic_error("Already has root");
        }
        
        node* n = new node();
        n->elem = num;
        n->children = new node*[10];
        n->parent = nullptr;\
        n->num_child = 0;
        
        root = n;
        size++;
        return root;
    }
    
    node* addChild(node* parent, int num){
        node* n = new node();
        n->elem = num;
        n->parent = parent;
        n->children = new node*[10];
        n->num_child = 0;
        parent->children[parent->num_child++] = n;
        
        size++;
        return n;
    }
    
    void remove(node* n){
        
        if(n==root && n->num_child==0){
            root = nullptr;
            size--;
            return;
        }
        
        if(n->num_child != 0){
            cout << n->elem << " has children\n";
            return;
        }
        
        bool isFound = false;
        for (int i = 0; i<n->parent->num_child; i++){
            if(n == n->parent->children[i]){
                for (int j = i; j<n->parent->num_child-1; j++){
                    n->parent->children[j] = n->parent->children[j+1];
                }
                n->parent->num_child--;
                isFound = true;
                break;
            }
        }
        size--;
    }
    
    int getSize(){
        return size;
    }
    
    node* getRoot(){
        return root;
    }
};