#include <iostream>
#include "SpotifyPlaylist.hpp"
using namespace std;

int main() {
    List* playlist = new SpotifyPlaylist();
    char op;
    string title, artist;
    song* temp;
    bool val;

    cout << "=== Spotify Doubly Linked List ===\n";
    cout << "a. Add Song at End\n";
    cout << "b. Add Song at Start\n";
    cout << "c. Delete Song by Title\n";
    cout << "d. Show Current Song\n";
    cout << "e. Next Song\n";
    cout << "f. Previous Song\n";
    cout << "g. Display Playlist (Forward)\n";
    cout << "h. Display Playlist (Reverse)\n";
    cout << "i. Search Song\n";
    cout << "j. Clear Playlist\n";
    cout << "k. Check if Playlist is empty\n";
    cout << "l. Show Number of Songs\n";
    cout << "x. Exit\n";

    do {
        cout << "\nOp: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 'a':
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                playlist->insertSongAtEnd(title, artist);
                break;
            case 'b':
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                playlist->insertSongAtFront(title, artist);
                break;
            case 'c':
                cout << "Enter title to delete: ";
                getline(cin, title);
                temp = playlist->deleteSong(title);
                if(!temp){
                    cout << "Song not found.\n";
                } else {
                    cout << "Successfully deleted " << temp->title << " by " << temp->artist << ".\n";
                }
                break;
            case 'd':
                playlist->showCurrentSong();
                break;
            case 'e':
                playlist->nextSong();
                break;
            case 'f':
                playlist->prevSong();
                break;
            case 'g':
                playlist->displayPlaylist();
                break;
            case 'h':
                playlist->displayPlaylistReverse();
                break;
            case 'i': {
                cout << "Enter title to search: ";
                getline(cin, title);
                song* found = playlist->search(title);
                if (found)
                    cout << "Found: " << found->title << " by " << found->artist << endl;
                else
                    cout << "Song not found.\n";
                break;
            }
            
            case 'j':
                cout << "Playlist cleared. Number of songs removed: " << playlist->clearPlaylist() << endl;
                break;
            case 'k':
                val = playlist->isEmpty();
                if(val){
                    cout << "Playlist is empty.\n";
                } else {
                    cout << "Playlist is not empty.\n";
                }
                break;
            case 'l':
                cout << "Number of songs in playlist: " << playlist->countSongs() << endl;
                break;
            case 'x':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }
    } while (op != 'x');
}