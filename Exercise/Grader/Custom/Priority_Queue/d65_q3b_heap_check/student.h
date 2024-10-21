#ifndef __STUDENT_H
#define __STUDENT_H

#include "priority_queue.h"

template <typename T, typename Comp>
bool CP::priority_queue<T, Comp>::check() {
  // Your code here
  // Return something
  size_t i = 0;
  while((2*i + 1) < mSize){ // check that does 
    T par_node = mData[i],l = mData[2*i + 1];
    T r = l;
    if(2*i + 2 < mSize) r = mData[2*i + 2]; // if right child exist update r
    if(!((mLess(r,par_node))&&(mLess(l,par_node)))){
      return false;
    }
    i++;
  }
  return true;
}

#endif