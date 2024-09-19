#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include <stack>

template <typename T>
void CP::stack<T>::multi_pop(size_t K) {
  //write your code here
  size_t size = std::min(mSize,K);
  for(size_t i = 0;i < size;i++){
    pop();
  }
}

template <typename T>
std::stack<T> CP::stack<T>::remove_top(size_t K) {
  //write your code here
  //
  //don't forget to return an std::stack
  size_t size = std::min(mSize,K);
  std::vector<T> v(size);std::stack<T> del;
  for(int i = size-1;i >= 0;i--){
    v[i] = top();
    pop();
  }
  for(auto &it:v){
    del.push(it);
  }
  return del;
}

#endif
