 #include "mybinarytree.hpp" // already implemented, though hidden

class BST {
	BinaryTree* tree = new MyBinaryTree();
    
public:
   bool search(int num) { // TODO implement me
	    node* temp = searchHelper(num, tree->getRoot());
	    if(temp) return true;
        return false;
	}
	
	node* searchHelper(int num, node* n){
	    if(!n) return nullptr;
	    if(n && n->elem == num){
	        return n;
	    }
	    
	   return n->elem > num ? searchHelper(num, n->left) : searchHelper(num, n->right);
	}



	bool insert(int num) { // TODO implement me
    	if(!tree->getRoot()){
    	    tree->addRoot(num);
            return true;
    	}
	    return insertHelper(num, tree->getRoot()) != nullptr;
	}
	
	node* insertHelper(int num, node* n){
	    if(num < n->elem){
	        return tree->left(n) ? insertHelper(num, n->left) : tree->addLeft(n, num);
	    }
	    else if (num >  n->elem){
	       return tree->right(n) ? insertHelper(num, n->right) : tree->addRight(n, num);
	    } else {
	        return nullptr;
	    }
	}

    // TODO implement remove method
    // You can add helper methods like what is done for insert and search
    bool remove(int num) {
        node* temp = searchHelper(num, tree->getRoot());
        if(!temp) return false;
        
        if((!temp->right && !temp->left) || temp->right && !temp->left || temp->left && !temp->right){
            tree->remove(temp);
            return true;
        }
        
        else{
            node* temp2 = temp->right;
            while(temp2->left){
                temp2 = temp2->left;
            }
            temp->elem = temp2->elem;
            tree->remove(temp2);
            return true;
        }
        
        return false;
        
    }

	void print() { // DO NOT modify
		tree->print();
	}
};