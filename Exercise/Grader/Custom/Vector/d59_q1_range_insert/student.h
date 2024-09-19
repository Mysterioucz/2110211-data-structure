#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  size_t pos = position - &mData[0];
  ensureCapacity(mSize + (last - first));
  iterator it = first;
  mSize += (last - first);
  for(size_t i = mSize - 1; i >= pos + (last - first);i--){
    mData[i] = mData[i - (last-first)];
  }
  for(size_t i = pos;i < pos + (last - first);i++){
    mData[i] = *(it++);
  }
}

#endif
