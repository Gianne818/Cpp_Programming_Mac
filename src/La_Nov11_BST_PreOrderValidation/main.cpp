#include <iostream>
using namespace std;


struct node {
    int elem;
    node* parent, *left, *right;
};

class BST {
    node* root;
    node* create_node(int num, node* parent){
        node* n = new node();
        n->elem = num;
        n->parent = parent;
        n->left = n->right = nullptr;
        return n;
    }
public:
    BST(){
        root = nullptr;
    }
    
    node* insert(int num, node* n){
        if(!root){
            return root = create_node(num, nullptr);
        }
        
        if(num <  n->elem){
            n->left ? insert(num, n->left) : n->left = create_node(num, n);
        } 
        else if (num > n->elem){
            n->right ? insert(num, n->right) : n->right = create_node(num, n);
        }
        
        return n;
    }
    
    node* getRoot(){
        return root;
    }
};

int* preOrder(node* n){
    static int* preOrderArray = (int*) calloc(20, sizeof(int));
    static int ctr = 0;
    
    if(!n) return preOrderArray;
    
    preOrderArray[ctr++] = n->elem;
    preOrder(n->left);
    preOrder(n->right);
    return preOrderArray;
}

bool validate(int s, int* arr){
    BST* tree = new BST();
    for(int i = 0; i<s; i++){
        tree->insert(arr[i], tree->getRoot());
    }
    
    int* arr2 = preOrder(tree->getRoot());
    for (int i = 0; i<s; i++){
        if(arr[i] != arr2[i]) return false;
    }
    return true;
  
}


int main (){
    int s;
    cout << "Enter number of elements: ";
    cin >> s;
    
    int arr[s];
    cout << "Enter preorder: ";
    for (int i = 0; i<s; i++){
        cin >> arr[i];
    }
    
    if(validate(s, arr)){
        cout << "VALID";
    } else {
        cout << "INVALID";
    }
}