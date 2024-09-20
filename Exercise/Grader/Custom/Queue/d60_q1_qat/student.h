#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
T CP::queue<T>::operator[](int idx) {
  //write something here
  if(idx >= 0){
    return mData[(mFront + idx) % mCap];
  }
  size_t mBack = (mFront + mSize - 1) % mCap;
  int pos = (mBack + idx + 1) % mCap;
  return mData[pos];
  // you need to return something
  // return 
}

#endif
