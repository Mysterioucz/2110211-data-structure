#ifndef __STUDENT_H_
#define __STUDENT_H_

using namespace std;

#include <queue>

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  size_t c = 0;
  for(int i = 0;i < mSize;i++){
    if(!mLess(mData[i],mData[pos])){
      if(mData[i]!=mData[pos]){
        c++;
      }
    }
  }
  return c;
}

#endif
