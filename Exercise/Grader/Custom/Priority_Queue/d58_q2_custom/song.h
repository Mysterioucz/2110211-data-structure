#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};


//  you have to write something below this line 
class q1Comp{
  public:
    bool operator()(Song s1,Song s2){
      return make_tuple(s1.artist,s1.title,s1.count) > make_tuple(s2.artist,s2.title,s2.count);
    }
};
class q2Comp{
  public:
    bool operator()(Song s1,Song s2){
      if(s1.count != s2.count){
        return s1.count < s2.count;
      }else{
        return make_pair(s1.artist,s1.title) > make_pair(s2.artist,s2.title);
      }
    }
};
//  you *MIGHT* have to change the declaration of pq1 and pq2
CP::priority_queue<Song,q1Comp> pq1;
CP::priority_queue<Song,q2Comp> pq2;

#endif
