#include <iostream>
using namespace std;

struct song {
    string title;
    string artist;
    song* next, *prev;
};