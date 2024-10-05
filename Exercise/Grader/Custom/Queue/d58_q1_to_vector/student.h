#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
  std::vector<T> res;
  //write your code only here
  int stop = k > mSize ? mSize:k;
  for(int i = 0 ;i < stop;i++){
    res.push_back(mData[(mFront + i) % mCap]);
  }
  return res;
}

template <typename T>
CP::queue<T>::queue(iterator from,iterator to) {
  //write your code only here
  mSize = to - from;
  mCap = to - from;
  mData = new T[mSize]();
  mFront = 0;
  for(int i = 0;i < mSize;i++){
    mData[i] = *(from + i);
  }
}

#endif
