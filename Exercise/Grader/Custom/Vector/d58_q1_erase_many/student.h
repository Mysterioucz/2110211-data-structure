#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  T *pData = mData;
  int count = 0,j = 0;
  mSize -= pos.size();
  mData = new T[mSize];
  mCap = mSize;
  for(size_t i = 0;i < mSize;i++){
    while((i + count) == pos[j]){
      count++;
      j = j+1 >= pos.size() ? j:j+1;
    }
    mData[i] = pData[i + count];
  }
  delete [] pData;
  // for(auto it:pos){
  //   erase(&mData[0] + it - count);
  //   count++;
  // }
}

#endif
