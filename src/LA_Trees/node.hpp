#include <cstdlib>
#include <math.h>

struct node {
    node **children;
    node *parent;
    int num_child;
    int elem;

    int depth() {
        // TODO implementation [+10 pts]
        int count = 0;
        node* temp = this;
        while(temp!=nullptr){
            temp  = temp->parent;
            count++;
        }
        return count-1;
    }


    int height() {
        if(num_child == 0) return 0;
        int maxHeight = 0;
        for (int i = 0; i<num_child; i++){
            int curHeight = children[i]->height();
            if(curHeight > maxHeight) maxHeight = curHeight;
        }
        return maxHeight+1;
    }
    
    
    
    
};