#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

//DO NOT INCLUDE ANYTHING


template <typename T>
CP::stack<T>::stack(typename std::set<T>::iterator first,typename std::set<T>::iterator last) {
  //write your code ONLY here
  int size = std::distance(first,last);
  mSize = size;
  mCap = size;
  mData = new T[size]();
  auto it = last;
  it--;
  for(size_t i = 0;i < size;i++){
    mData[i] = *it;
    it--;
  }
}

#endif
