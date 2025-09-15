#include <iostream>
#include <cmath>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
private:
    int size = 5;
    Entry* sb = (Entry*)malloc(size*sizeof(Entry));
    int ctr = 0;
    Entry* scoreboard = sb;

public:
    void checkRanking(Entry* e){
        int i;
        for (i = 0; i<ctr; i++){
            if(e->score > sb[i].score){
                break;
            }
        }

        for (int j = ctr; j>i; j--){
            sb[j] = sb[j-1];
        }   
        sb[i] = *e;
        ctr++;
        scoreboard = sb;
        cout << "Successfully added: " << sb[i].name << ", " << sb[i].score << endl;
        
    }

    void resizeAdd(){
        int newSize = ceil(size*1.5);
        if(newSize==size){
            cout << "Size increased by 1.\n";
            newSize++;
        } else {
            cout << "Reallocation triggered.Size increased by " << newSize-size << endl;
            cout << "New size: " << newSize << endl;
            sb = (Entry*) realloc(sb, newSize*sizeof(Entry));
        }
        size = newSize;
    }

    void add(Entry* e){
        if(ctr==size){
            resizeAdd();
        }
        checkRanking(e);
        
    }

    void print(){
        for (int i = 0; i<ctr; i++){
            cout << "Place " << i+1 << ": " << sb[i].name << ", " << sb[i].score << endl;
        }
    }
    
    void resizeDown(){
        int newSize = ceil(size*(2.0/3.0)); //using floor, the size can go to zero and cause error
        if(size==newSize && newSize>1){
            newSize--;
            cout << "Size decreased by 1.\n";
        } else {
            cout << "Reallocation triggered. Size decreased by " << size-newSize << endl;
            cout << "New size: " << newSize << endl;
            sb = (Entry*)realloc(sb, newSize*sizeof(Entry));
        }
        size = newSize;
    }

    string remove(string name){
        string temp;
        for (int i = 0; i<ctr; i++){
            if(sb[i].name == name){
                 temp = sb[i].name;
                for (int j = i; j<ctr-1; j++){
                    sb[j] = sb[j+1];
                }
                ctr--;
                if(ctr <= ceil(size*(2.0/3.0))){
                    resizeDown();
                }
                return temp;
            }
        }
        return "Error";
    }

    void displayScoreBoard(){
        for (int i = 0; i<6; i++){
            cout << "Place " << i+1 << ": " << scoreboard[i].name << ", " << scoreboard[i].score << endl;
        }
    }

};