#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
typename CP::list<T>::iterator CP::list<T>::reverse(iterator a, iterator b) {
  //write your code here
  CP::list<T>::iterator it = a;
  while((it != b)&&(it != --b)){ // implement like std::reverse by using std::iter_swap definition
    std::swap(*it,*b);
    it++;
  }
  return a;
}

#endif
