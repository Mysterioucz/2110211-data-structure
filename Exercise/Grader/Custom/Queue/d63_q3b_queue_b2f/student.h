#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here
  if(!empty()){
    // std::reverse(mData + mFront,mData + (mFront + mSize)%mCap);
    T *pData = mData;
    for(int i = 0;i < mSize;i++){
      mData[mFront + i] = pData[(mFront + mSize - 1 - i)%mCap]
    }
  }
}

#endif
