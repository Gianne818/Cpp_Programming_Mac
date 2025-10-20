#include <iostream>
#include "List.hpp"
using namespace std;

class SpotifyPlaylist : public List{
  int size;
  song head, tail, *current;
  
  song* addBetween(string title, string artist, song* pred, song* succ){
      song* s = new song();
      s->title = title;
      s->artist = artist;
      
      s->prev = pred;
      s->next = succ;
      
      pred->next = s;
      succ->prev = s;
      size++;
      
      
      return s;
  }
  
  void deleteNode(song* s){
      s->prev->next = s->next;
      s->next->prev = s->prev;
      
      delete s;
      size--;
  }
  
  void nextSong(){
      if(current && current->next != &tail){
          current = current->next;
      }
      showCurrentSong();
      
  }
  
  void prevSong(){
      if(current && current->prev != &head){
          current = current->prev;
      }
      showCurrentSong();
  }
  
  void showCurrentSong(){
      if(!current){
          cout << "No song.\n";
      } else 
      cout << "Current song: " << current->title << " by " << current->artist << endl;
  }
  
  
public: 
    SpotifyPlaylist(){
        size = 0;
        
        head.next = &tail;
        tail.prev = &head;
        
        head.prev = nullptr;
        tail.next = nullptr;
        current = nullptr;
    }
    
    void insertSongAtEnd(string title, string artist){
        song* temp = addBetween(title, artist, tail.prev, &tail);
        if(!current) current = temp;
    }
    
    void insertSongAtFront(string title, string artist){
        song* temp = addBetween(title, artist, &head, head.next);
        if(!current) current = temp;
    }
    
    song* deleteSong(string title){
        song* temp = head.next;
        while(temp!=&tail){
            if(temp->title == title){
                song* toReturn = new song(*temp);
                deleteNode(temp);
                return toReturn;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    
    int clearPlaylist(){
        int count = 0;
        song* temp = head.next;
        while(temp!=&tail){
            song* temp2 = temp;
            deleteNode(temp2);
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    song* search(string title){
        song* temp = head.next;
        while(temp!=&tail){
            if(temp->title == title){
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
    
    
    bool isEmpty(){
        return size==0;
    }
    
    int countSongs(){
        return size;
    }
    void displayPlaylist(){
        song* temp = head.next;
        while(temp!=&tail){
            cout << temp->title << " by " <<temp->artist  << endl;
            temp = temp->next;
        }
    }
    
    void displayPlaylistReverse(){
        song* temp = tail.prev;
        while(temp!=&head){
            cout << temp->title << " by " <<temp->artist  << endl;
            temp = temp->prev;
        }
    }
    
    
};