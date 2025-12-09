#include <iostream>
using namespace std;


bool preOrderValidation(int* arr, int start, int end){
    int root = arr[start];
    
    if(start >= end) return true;
    
    int i;
    //scan in first half of preorder
    //find the end of the left subtree where the elements are now greater than root
    for(i = start + 1; i<=end; i++){
        if(root < arr[i]){
            break;
        }
    }
    
        
    int leftSubTreeEnd = i-1;
    
    //validate rigiht subtree. if an element is smaller than the root, it is false
    for(int k = i; k<=end; k++){
        if(root > arr[k]){
            return false;
        }
    }
    
    bool leftTree = preOrderValidation(arr, start+1, leftSubTreeEnd);
    bool rightTree = preOrderValidation(arr, i, end); //i is the start of the right subtree
    return leftTree && rightTree;
}

bool postOrderValidation(int* arr, int start, int end){
    int root = arr[end];
    if(start>=end) return true;

    int i;
    //find start of right subtree, where elements are greater than root.
    //stop when elements < root, meaning it is the end index of left subtree
    for (i = end-1; i>=start; i--){
        if(arr[i] < root){
            break;
        }
    }

    //validate leftSubTree range. arr[start] to arr[i] must be less than (<) root. if greater, false
    for (int k = start; k<=i; k++){
        if(arr[k] > root){
            return false;
        }
    }

    bool leftTree = postOrderValidation(arr, start, i); //i is last index of left subtree
    bool rightTree = postOrderValidation(arr, i+1, end-1); //i+1 is the start index of the right subtree
    return leftTree && rightTree;
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
    
    bool res = preOrderValidation(arr, 0, s-1);
    if(res) cout << "VALID";
    else cout << "INVALID";
}



// #include <iostream>
// using namespace std;


// struct node {
//     int elem;
//     node* parent, *left, *right;
// };

// class BST {
//     node* root;
//     node* create_node(int num, node* parent){
//         node* n = new node();
//         n->elem = num;
//         n->parent = parent;
//         n->left = n->right = nullptr;
//         return n;
//     }
// public:
//     BST(){
//         root = nullptr;
//     }
    
//     node* insert(int num, node* n){
//         if(!root){
//             return root = create_node(num, nullptr);
//         }
        
//         if(num <  n->elem){
//             n->left ? insert(num, n->left) : n->left = create_node(num, n);
//         } 
//         else if (num > n->elem){
//             n->right ? insert(num, n->right) : n->right = create_node(num, n);
//         }
        
//         return n;
//     }
    
//     node* getRoot(){
//         return root;
//     }
// };

// int* preOrder(node* n){
//     static int* preOrderArray = (int*) calloc(20, sizeof(int));
//     static int ctr = 0;
    
//     if(!n) return preOrderArray;
    
//     preOrderArray[ctr++] = n->elem;
//     preOrder(n->left);
//     preOrder(n->right);
//     return preOrderArray;
// }

// bool preOrderValidation(int s, int* arr){
//     BST* tree = new BST();
//     for(int i = 0; i<s; i++){
//         tree->insert(arr[i], tree->getRoot());
//     }
    
//     int* arr2 = preOrder(tree->getRoot());
//     for (int i = 0; i<s; i++){
//         if(arr[i] != arr2[i]) return false;
//     }
//     return true;
  
// }


// int main (){
//     int s;
//     cout << "Enter number of elements: ";
//     cin >> s;
    
//     int arr[s];
//     cout << "Enter preorder: ";
//     for (int i = 0; i<s; i++){
//         cin >> arr[i];
//     }
    
//     if(preOrderValidation(s, arr)){
//         cout << "VALID";
//     } else {
//         cout << "INVALID";
//     }
// }