#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"
#include <algorithm>

template <typename T>
std::vector<std::vector<T>>  CP::stack<T>::split_stack(int k) const {
  //your code here
  using std::vector;
  vector<vector<T>> res(k);
  for(size_t i = 0;i < k;i++){
    int topPos = (mSize - 1) - i;
    while(topPos >=0 ){
      res[i].insert(res[i].begin(),mData[topPos]);
      topPos -= k;
    }
  }
  return res;
  //should return something
}

#endif

