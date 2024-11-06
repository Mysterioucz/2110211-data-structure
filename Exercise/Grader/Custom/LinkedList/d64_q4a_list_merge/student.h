#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls) {
  //write your code here
  for(auto it = ls.begin(); it != ls.end(); it++) {
    if((*it).mSize == 0) continue;

    auto it_begin = (*it).begin();
    auto it_end = ((*it).mHeader)->prev;
    auto this_end = mHeader->prev;

    this_end->next = it_begin.ptr;
    it_begin.ptr->prev = this_end;
    it_end->next = mHeader;
    mHeader->prev = it_end;
    
    mSize += (*it).mSize;
    (*it).mHeader->next = (*it).mHeader; // point to it's self
    (*it).mHeader->prev = (*it).mHeader; // point to it's self
    (*it).mSize = 0;
  }
}

#endif
