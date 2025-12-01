 #include "mybinarytree.hpp" // already implemented, though hidden
 #include <queue>
 using namespace std;

class Heap {
	BinaryTree* tree = new MyBinaryTree();

	void heapifyUp(node* n){
		while(n->parent && n->elem > n->parent->elem){
			swap(n->elem, n->parent->elem);
		}
	}

	void heapifyDown(node* n){
		while(n){
			node* smallest = n;

			if(n->left && n->left->elem < n->elem){
				smallest = n->left;
			}

			if(n->right && n->right->elem < n->elem){
				smallest = n->right;
			}	

			if(smallest==n) break;
			swap(smallest->elem, n->elem);
			n = smallest;
		}
	}

	node* getLastNode(){
		node* n = tree->getRoot();
		if(!n) return nullptr;
		node* last;
		queue<node*> q;
		q.push(n);

		while(!q.empty()){
			last = q.front();
			q.pop();
			if(n->left) q.push(n->left);
			if(n->right) q.push(n->right);
		}

		return last;
	}

	void swap(int &a, int &b){
		int temp = a;
		a = b;
		b = temp;
	}

public:
	void insert(int num){
		if(!tree->getRoot()){
			tree->addRoot(num);
			return;
		}
		node* root = tree->getRoot();
		queue<node*> q;
		q.push(root);
		while(!q.empty()){
			node* curr = q.front();
			q.pop();
			if(!curr->left){
				tree->addLeft(curr, num);
				heapifyUp(curr);
			}
			else if (!curr->right){
				tree->addRight(curr, num);
				heapifyUp(curr);
			} else {
				q.push(curr->left);
				q.push(curr->left);
			}
		}
	}

	void removeRoot(){
		node* root = tree->getRoot();
		if(!root->left && !root->right){
			tree->remove(root);
			return;
		}

		if(root->left){
			if(!root->right){

			}
		}
	}

	void print() { // DO NOT modify
		tree->print();
	}
};