#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <assert.h>

template <typename T,typename Comp>
void CP::priority_queue<T,Comp>::change_value(size_t pos,const T& value) {
  //write your code here
  T old_val = mData[pos];
  mData[pos] = value;
  if(mLess(value,old_val)){ // Check that do we need to fix the value position to be able to be heap
    fixDown(pos);
  }else{
    fixUp(pos);
  }
}

#endif
