#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
T& CP::vector_no_move<T>::operator[](int idx) {
  //your code here
  auto row = std::lower_bound(aux.begin(),aux.end(),idx + 1);// The problem guarantee that index will be in range
  int index = row - aux.begin(), prev_cap = 0;
  if(index > 0){
    prev_cap = aux[index - 1];
  }
  return mData[index][idx - prev_cap];
}

template <typename T>
void CP::vector_no_move<T>::expand_hook() {
  //your code here
  //you MAY need this function
  aux.push_back(mCap); 
}

#endif
