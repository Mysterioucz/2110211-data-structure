#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::mirror() {
  //write your code here
  T *pData = mData; 
  mData = new T[mSize*2];
  // Copy Old value to new Dynamic array
  for(size_t i = 0;i < mSize;i++){
    mData[i] = pData[i];
  }
  // Mirroring value to Dynamic array
  for(size_t i = mSize;i < 2*mSize;i++){
    mData[i] = pData[mSize - (i - (mSize - 1))];
  }
  mSize *= 2;
  mCap = mSize;
  // Delete old array
  delete [] pData;
}

#endif
