#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <set>
#include <vector>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
  // Write code here
  std::sort(itrs.begin(),itrs.end());
  std::set<T> c;
  std::vector<int> pos(mSize,0);
  int i = -1,count = 0;
  for(auto it:itrs){
    if(c.find(*it) == c.end()){
      c.insert(c.end(),*it);
    }else{
      if(i == -1){
        i = it-begin();
      }
      pos[it-begin()] += 1;
      count++;
    }
  }
  int j = i;
  
  while(i < mSize - count){
    j += pos[j];
    mData[i] = mData[j];
    i++;
    j++;
  }
  mSize -= count;

}

#endif
