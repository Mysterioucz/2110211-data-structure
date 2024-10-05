#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos) {
  //write your code here
  T val = mData[(mFront + pos)%mCap];
  for(int i = 0;i < mSize - pos;i++){
    int p = (mFront + pos + i)%mCap;
    if(p == mCap - 1){
      mData[p] = mData[0];
    }else{
      mData[p] = mData[p + 1];
    }
  }
  mData[(mFront + mSize - 1)%mCap] = val;
}

#endif
