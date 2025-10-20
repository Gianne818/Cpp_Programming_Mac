#include "Song.hpp"
using namespace std;

class List {
public:
    virtual void insertSongAtEnd(string, string) = 0;
    virtual void insertSongAtFront(string, string) = 0;
    virtual song* deleteSong(string) = 0;
    virtual void displayPlaylist() = 0;
    virtual void displayPlaylistReverse() = 0;
    virtual void nextSong() = 0;
    virtual void prevSong() = 0;
    virtual void showCurrentSong() = 0;
    virtual song* search(string) = 0;
    virtual int clearPlaylist() = 0;
    virtual bool isEmpty() = 0;
    virtual int countSongs() = 0;
};