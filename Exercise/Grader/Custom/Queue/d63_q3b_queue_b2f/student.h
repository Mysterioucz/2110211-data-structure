#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::back_to_front() {
  //write your code here
  if(!empty()){
    // Sol1: To Slow O(n)
    // T back = mData[(mFront + mSize - 1)%mCap];
    // for(int i = (mFront + mSize - 1)%mCap;i != mFront;i--){
    //   if(i < 0)i = mCap - i;
    //   if(i==0){
    //     mData[i] = mData[mCap - 1];
    //   }else{
    //     mData[i] = mData[i - 1];
    //   }
    // }
    // mData[mFront] = back;
    //Sol 2
    if(mFront > 0){ // ถ้าก่อน mFront มีที่ว่างให้ย้ายตัวท้ายมาเลย
      mData[mFront - 1] = mData[(mFront + mSize - 1)%mCap];
      mFront--;
    }else{//ถ้า mFront == 0 หรือก็คือ หน้า mFront ไม่ว่างเลยก็ต้องเลื่อน
      mFront = mCap - 1;
      mData[mFront] = mData[(mFront + mSize)%mCap];// ไม่ - 1 ออกเพราะเรา update mFront แล้ว
    }
  }
}

#endif
