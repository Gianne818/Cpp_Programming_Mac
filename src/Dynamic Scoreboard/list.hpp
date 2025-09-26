#include "entry.hpp"

class List {
    virtual void add(Entry*) = 0;
    virtual void printScoreBoard() = 0;
    virtual void printBoard() = 0;
   // virtual Entry* remove(string name) = 0;
    //virtual Entry get(int pos) = 0;
    //void checkRanking(Entry* e)
    //void resizeUp()
    //void resizeDown()
};