#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <math.h>

template <typename T,typename Comp >
int CP::priority_queue<T,Comp>::height() const {
  //write your code here
  if(mSize == 0) return -1;
  if(mSize == 1) return 0;
  if(mSize == 2) return 1;
  return log2(mSize)/1;
}

#endif

