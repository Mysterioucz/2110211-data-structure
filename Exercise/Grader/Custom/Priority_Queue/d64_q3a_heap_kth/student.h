#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  using namespace std;
  vector<T> v;
  for(int i = 0;(i < mSize)&&(v.size() <= 7);i++){
    v.push_back(mData[i]);
  }
  sort(v.rbegin(),v.rend(),mLess);
  return v[k-1];
}

#endif
