#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <math.h>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> r;
  if(k <= log2(mSize)){
    int idx = pow(2,k) - 1;
    int bound = pow(2,k+1) - 1;
    while((idx < bound)&&(idx < mSize)){
      r.push_back(mData[idx]);
      idx++;
    }
  }
  std::sort(r.begin(),r.end(),mLess);
  std::reverse(r.begin(),r.end());
  return r;
}

#endif

