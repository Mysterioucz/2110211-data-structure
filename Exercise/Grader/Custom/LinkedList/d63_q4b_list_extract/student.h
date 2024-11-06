#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::list<T>::extract(const T& value,iterator a, iterator b,CP::list<T>& output) {
  //write your code here
  if(mSize == 0) return;
  while(a != b){
    if(*a == value){
      auto tmp = a;
      a++;
      tmp.ptr->prev->next = tmp.ptr->next;
      tmp.ptr->next->prev = tmp.ptr->prev;
      tmp.ptr->next = output.begin().ptr;
      tmp.ptr->prev = output.mHeader;
      output.begin().ptr->prev = tmp.ptr;
      output.mHeader->next = tmp.ptr;
      mSize--;
      output.mSize++;
    }else{
      a++;
    }
  }

}

#endif
