#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  // your code here
  int eSize = (mSize + k - 1)/k;// (mSize + k - 1)/k for round up
  std::vector<int> s(k,eSize); 
  for(int i = 0;i < (eSize * k) - mSize;i++){
    s[k - 1 - i]--;
  }
  output.resize(k);
  int j = 0;
  for(int i = 0;i < mSize;i++){
    if(output[j].size() == s[j]){
      j++;
    }
    output[j].push(mData[(mFront + i)%mCap]);
  }

}

#endif
