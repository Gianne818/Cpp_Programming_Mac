#include <iostream>
using namespace std;

//A binary search tree (BST) is a binary tree where
// 1. A node's left child and all of its descendants must have smaller values than the node.
// 2. A node's right child and all of it's descendants must have greater values than the node.
// 3. Both left and right subtrees must also be BSTs.

//It is efficient for searching, inserting, and deleting (O(log n)) if the tree is balanced.
//Unbalanced trees can degrade performance to O(n).

struct Node {
    int data;
    Node* left;
    Node* right;
    Node (int data) : data(data), left(nullptr), right(nullptr){}
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
};

void Tree::inOrderTraversal(Node* root){
    if (root == nullptr) return;
    
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

Node* search(Node* root, int target){
    if(root==nullptr || root->data==target){
        return root;
    }
    if(target < root->data) {
        return search(root->left, target);
    }
    return search(root->right, target);
}

Node* Tree::insert(Node* root, int data){
    if(root == nullptr) return new Node(data);

    if(data < root->data){
        root->left = insert(root->left, data);
    } else if (data > root->data){
        root->right = insert(root->right, data);
    }
    return root; 
    //Needed because after return new Node, it returns to the last function call.
    //Previous function calls have no return statement.
}

Node* Tree::minValueNode(Node* root){
    Node* temp = root;
    while(temp->left!=nullptr){
        temp = temp->left;
    }
    return temp;
}


Node* Tree::deleteNode(Node* root, int data){
    if(root==nullptr) return root;

    if(data < root->data){
        root->left =  deleteNode(root->left, data);
    } else if (data > root->data){
        root->right = deleteNode(root->right, data);
    } 
    
    else {
        //if one child, left is empty
        if(root->left==nullptr){
            Node* temp = root->right;
            delete root;
            return temp; //returns to the previous if/else-if statements and reconnect to parent to maintain bst.
        }
        //if one child, right is empty
        if(root->right==nullptr){
            Node* temp =  root->left;
            delete root;
            return temp;
        }

        //if deleted node has children both left and right
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        //we dont delete the actual node.
        //instead, we change the value of the node to its in-order successor.
        //we delete the actual in-order successor node.
    }
    return root;
}

int main (){
    Tree t1;
    Node* root = new Node(7);
    t1.insert(root, 3);
    t1.insert(root, 13);
    t1.insert(root, 8);
    t1.insert(root, 15);
    t1.insert(root, 6);

    t1.inOrderTraversal(root);
    cout << endl;

    cout << "The minimum value node is: " << t1.minValueNode(root)->data << endl;
    t1.deleteNode(root, 7);

    t1.inOrderTraversal(root);

}

//Sample algorithm when doing insert(root, 6);
/*
insert(r=7, 6)
root(7)->left = insert(r=3, 6);
root(3)->right = insert(r=nullptr, 6);
return new Node(6)
root(3)->right = new Node(6)
return root(3)
root(7)->left = root(3)
return root(7)
*/