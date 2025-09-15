#include <iostream>
#include <cmath>
#include "list.hpp"
using namespace std;

class ArrayList : public List {
private:
    int size = 0;
    Entry scoreboard[5];

public:
    ArrayList(){}
    ArrayList(int size){
        this->size = size;
    }
    void add (Entry* e){
        if(size==5){
            if(e->score < scoreboard[4].score){
                return;
            }
        }

        int i;
        for (i = 0; i<size; i++){
            if(e->score > scoreboard[i].score)
                break;
        }

        for (int j = size; j>i; j--){
            scoreboard[j] = scoreboard[j-1];
        }
        scoreboard[i] = *e;
        if(size < 5) size++;
        cout << "Successfully added: " << scoreboard[i].name << ", " << scoreboard[i].score << endl;
        return;
    }

    void print(){
        for (int i = 0; i<size; i++){
            cout << "Place " << i+1 << ": " << scoreboard[i].name << ", " << scoreboard[i].score << endl;
        }
    }

    Entry* remove (string name){
        for (int i = 0; i<size; i++){
            if(scoreboard[i].name == name){
                Entry* temp = new Entry(scoreboard[i]);
                for (int j = i; j<size; j++){
                    scoreboard[j] = scoreboard[j+1];
                }
                size--;
                return temp;
            }
        }
        return nullptr;
    }

    Entry get(int pos){
        if(pos>5 || pos<1){
            return {-1, ""};
        } else if (pos>size){
            return {-2, ""};
        }
        return scoreboard[pos-1];
    }

};