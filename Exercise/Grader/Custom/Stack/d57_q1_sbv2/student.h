#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <iostream>

template <typename T>
size_t CP::stack<T>::size() const {
  //write your code here
  return v.size();
}

template <typename T>
const T& CP::stack<T>::top() const {
  //write your code here
  return v[v.size()-1];
}

template <typename T>
void CP::stack<T>::push(const T& element) {
  //write your code here
  v.push_back(element);
}

template <typename T>
void CP::stack<T>::pop() {
  //write your code here
  v.pop_back();
}

template <typename T>
void CP::stack<T>::deep_push(const T& element, int depth) {
  //write your code here
  int pos = (v.size()) - depth; // ไม่ต้องลบ Vsize เพราะ vSize คือตำแหน่งท้ายของ Vector ใหม้ ที่มีขนาด v.size() + 1
  v.push_back(element);// เพิ่มขนาด +1
  for(size_t i = v.size()-1;i > pos;i--){
    v[i] = v[i-1];
  }
  v[pos] = element;
}

template <typename T>
void CP::stack<T>::multi_push(const std::vector<T> &w) {
  //write your code here
  for(auto &e:w){
    push(e);
  }
}

template <typename T>
void CP::stack<T>::pop_until(const T& e) {
  //write your code here
  while((!v.empty())&&(top() != e)){
    v.pop_back();
  }
}

#endif

