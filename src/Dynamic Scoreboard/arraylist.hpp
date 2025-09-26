#include "list.hpp"
#include <iostream>
#include <cmath>

class ArrayList : public List {
    int size = 5;
    Entry* board = (Entry*)malloc(size*sizeof(Entry));
    int numEntry = 0;
    Entry* scoreboard = (Entry*) malloc (size*sizeof(Entry));

    void resizeUp(){
        int newSize = ceil(size*1.5);
        size = newSize;
        cout << "Reallocation up triggered. New size: " << size << endl;
        board = (Entry*) realloc(board, size*sizeof(Entry));
    }

    void resizeDown(){
        int newSize = floor(size*(2.0/3.0));
        size = newSize;
        cout << "Reallocation up triggered. New size: " << size << endl;
        board = (Entry*) realloc(board, size*sizeof(Entry));
    }

    void allocateScoreboard(){
        for (int i = 0; i<5; i++){
            scoreboard[i] = board[i];
        }
    }


public:
    void add(Entry* e){
        if(numEntry >= size){
            resizeUp();
        }
        //Entry* e = new Entry();

        int i;
        for (i = 0; i<numEntry; i++){ 
            //find ranking for e
            if(e->score > board[i].score){
                break;
            }
        }

        for (int j = numEntry; j>i; j--){
            board[j] = board[j-1];
        }

        board[i] = *e;
        numEntry++;
        if(i<5){
            allocateScoreboard();
        }
        cout << "Added successfully: " << board[i].name << ", " << board[i].score << endl;
    }

    Entry* removeAt(int pos){
        if(pos<1 || pos>numEntry){
            return nullptr;
        }

        Entry* e = new Entry();
        *e = board[pos-1];

        for (int i = pos-1; i<numEntry; i++){
            board[i] = board[i+1];
        }
        
        numEntry--;
        if(pos<=5){
            allocateScoreboard();
        }

        if(numEntry< floor(size*(2.0/3.0))){
            resizeDown();
        }

        return e;
    }

    void printBoard(){
        for (int i = 0; i<numEntry; i++){
            cout << board[i].name << " - " << board[i].score << endl;
        }
        cout << endl;
    }

    void printScoreBoard(){
        for (int i = 0; i<5; i++){
            cout << scoreboard[i].name << " - " << scoreboard[i].score << endl;
        }
    }

};