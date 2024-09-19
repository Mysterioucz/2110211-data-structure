#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)
  if(mSize == 0 && other.size() >= 1){
    return true;
  }else if(mSize >= 1 && other.size() >= 1){
    if(mData[0] < other[0]){
      return true;
    }else if(mData[0] == other[0]){
      if(mSize < other.size()){
        return true;
      }else if(mSize > other.size()){
        return false;
      }else{
        for(int i = 1;i < mSize;i++){
          if(mData[i]<other[i]){
            return true;
          }
        }
      }
    }
  }
  return false;
}

#endif
