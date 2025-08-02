#include <iostream>
using namespace std;

//There are two main tree traversals:
//Breadth First Search (BFS) - all nodes on the same level is visited first before proceeding to the next level.
//Depth First Search (DFS) - traverses down the tree until reaching the leaf nodes, exploring in a downward direction.

//Preorder - data -> left -> left
//Inorder - left -> data -> right
//Postorder - left -> right -> data

//The algorithms are like this (Sample algo is for preorder): 
// 1. Process current node (DATA) like printing.
// 2. Go to LEFT child.
//    - If it exists, repeat from step 1.
// 3. If no LEFT child, go to RIGHT child.
//    - If it exists, process its DATA and repeat from step 2.
// 4. Continue this pattern until all nodes are visited.
//That is implemented in recursive functions. The main usage of recursive functions is to traverse trees.
//Its more like... process data, left recursively, right recursively.

struct Node{
    int data;
    Node* left;
    Node* right;
    Node (int data) : data(data), left(nullptr), right(nullptr){}
};

class Tree{
    Node* root;    

public: 
    Tree(): root(nullptr){}
    Node* createRootNode(int data);
    Node* insertLeftChild(Node* parent, int data);
    Node* insertRightChild(Node* parent, int data);

    void preOrderTraversal(Node* root);
    void inOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
};

Node* Tree::createRootNode(int data){
    Node* newNode = new Node(data);
    root = newNode;
    root->left = nullptr;
    root->right = nullptr;
    return newNode;
}

Node* Tree::insertLeftChild(Node* parent, int data){
        if(parent==nullptr){
        cout << "Parent is null. Insertion aborted.\n";
        return nullptr;
    }

    if(parent->left!=nullptr){
        cout << "Node occupied. Insertion aborted.\n";
        return nullptr;
    }
    
    return parent->left = new Node(data);
}

Node* Tree::insertRightChild(Node* parent, int data){
    if(parent==nullptr){
        cout << "Parent is null. Insertion aborted.\n";
        return nullptr; 
    }

    if(parent->right!=nullptr){
        cout << "Node occupied. Insertion aborted.\n";
        return nullptr;
    }
    return parent->right = new Node(data);
}

void Tree::preOrderTraversal(Node* root){
    if(root==nullptr) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

void Tree::inOrderTraversal(Node* root){
    if(root==nullptr) return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void Tree::postOrderTraversal(Node* root){
    if(root==nullptr) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
    
}

int main (){
    Tree t1;
    Node* r = t1.createRootNode(1);
    Node* a = t1.insertLeftChild(r, 2);
    Node* b = t1.insertRightChild(r, 3);

    Node* c = t1.insertLeftChild(a, 4);
    Node* d = t1.insertRightChild(a, 5);

    Node* e = t1.insertLeftChild(b, 6);
    Node* f = t1.insertRightChild(b, 7);

    Node* g = t1.insertLeftChild(c, 8);
    Node* h = t1.insertRightChild(c, 9);
    
    cout << "\n\nPreorder traversal:\n";
    t1.preOrderTraversal(r);

    cout << "\n\nInorder traversal:\n";
    t1.inOrderTraversal(r);

    cout << "\n\nPostorder traversal:\n";
    t1.postOrderTraversal(r);

    cout << endl << endl;
}