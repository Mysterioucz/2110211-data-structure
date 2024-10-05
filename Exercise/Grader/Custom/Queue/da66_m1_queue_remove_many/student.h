#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
  // your code here
  if(!pos.empty()){
    std::sort(pos.begin(),pos.end());
  int count = 0;
  for(int i = 0;i < mSize - pos[0] - pos.size();i++){
    while((pos[0] + i + count) == pos[count]){
      count++;
    }
    mData[(mFront + pos[0] + i)%mCap] = mData[(mFront + pos[0] + i + count)%mCap];
  }
  mSize -= pos.size();
  }
}

#endif
