#ifndef _STUDENT_H_INCLUDED
#define _STUDENT_H_INCLUDED
#include "queue.h"

// Concept ของ Deque หมดเลย (Circular Buffer)
template <typename T>
void CP::queue<T>::reverse() {
  // Your code here
  aux = !aux; // ใช้ aux เพื่อระบุว่า reverse or not reverse
}

template <typename T>
const T& CP::queue<T>::front() const {
  // You MAY need to edit this function
  if(!aux){
    return mData[mFront];
  }
  return mData[(mFront + mSize - 1) % mCap];
}

template <typename T>
const T& CP::queue<T>::back() const {
  // You MAY need to edit this function
  if(!aux){
    return mData[(mFront + mSize - 1) % mCap];
  }
  return mData[mFront];
}

template <typename T>
void CP::queue<T>::push(const T& element) {
  // You MAY need to edit this function
  ensureCapacity(mSize + 1);
  if(!aux) mData[(mFront + mSize) % mCap] = element;
  else{
    mFront = (mFront + mCap - 1) % mCap;
    mData[mFront] = element;
  }
  mSize++;
}

template <typename T>
void CP::queue<T>::pop() {
  // You MAY need to edit this function
  if(!aux){
    mFront = (mFront + 1) % mCap;
  }// ในเคสที่ Reverse ไม่ต้องทำอะไร
  mSize--;
}

#endif