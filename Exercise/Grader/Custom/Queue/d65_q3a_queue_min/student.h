#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>

template <typename T>
template <typename Comp>
T CP::queue<T>::min_element(std::vector<size_t> pos,Comp comp) const {
  //your code here
  bool declare = false;
  T min;
  for(auto it:pos){
    if((it < mSize)){
      int idx = (mFront + it)%mCap;
      if(!declare){
        min = mData[idx];
        declare = true;
      }else if(comp(mData[idx],min)){
        min = mData[idx];
      }
    }
  }
  //should return something
  return min;
}

#endif
