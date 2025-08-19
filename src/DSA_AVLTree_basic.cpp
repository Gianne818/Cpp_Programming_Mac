#include <iostream>
using namespace std;

//AVL Tree is a type of BST that are self-balancing.
//Georgy (A)delson-(V)elsky and Evgenii (L)andis - Soviet inventors of AVL Trees in 1962
//Balance Factor is how we determine if the tree is balanced.

//It is the difference of the height of a node's left subtree and the node's right subtree
//bf = heightLeft - heightRight
//Acceptable balance factors are -1, 0, or +1.

//Should a node be imbalance, we proceed to the next node with a balanced factor and perform rotation there.
//If not balanced after insert/delete, perform rotations:
// 1. LL Rotation - right rotate
// 2. RR Rotation - left rotate
// 3. LR Rotation - left(on next balanced factor) then right(on unbalanced node) rotate
// 4. RL Rotation - right(on next balanced factor) then left(on unbalanced node) rotate

struct Node {
    int data, height;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr), height(1){}
};

class Tree {
    Node* root;
public: 
    Tree() : root(nullptr){}

    void inOrderTraversal(Node* root);
    Node* search(Node* root, int target);
    Node* insert(Node* root, int data);
    Node* minValueNode(Node* root);
    Node* deleteNode(Node* root, int data);

    // AVL-specific methods
    int getHeight(Node* root);
    int getBalance(Node* root);
    Node* rotateLeft(Node* pivot); //RR
    Node* rotateRight(Node* pivot); //LL
    Node* rebalance(Node* pivot);
};

//AVL-specific methods
int Tree::getHeight(Node* root){
    return root ? root->height : 0;
}

int Tree::getBalance(Node* root){
    if(root==nullptr) return 0;
    return getHeight(root->left) - getHeight(root->right);
}


Node* Tree::rotateLeft(Node* pivot){
    Node* newRoot = pivot->right;
    pivot->right = newRoot->left;
    newRoot->left = pivot;
    
    //udpate heights
    pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    
    //updating heights must be in that specific order, because pivot becomes a child of newRoot
    //update pivot->height first in order to calculate properly the height of newRoot, as each node stores its height.
    //You cannot update root->height directly, because after rotation, root may be modified to a new root.

    return newRoot;
}

Node* Tree::rotateRight(Node* pivot){
    Node* newRoot = pivot->left;
    pivot->left = newRoot->right;
    newRoot->right = pivot;

    pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}
