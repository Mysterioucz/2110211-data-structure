#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "stack.h"
#include <vector>

template <typename T>
void CP::stack<T>::v_split(std::vector<std::stack<T>> &output, size_t k) const {
  // Write code here
  size_t eSize = (mSize + k - 1) / k; // ทำแบบนี้เพื่อปัดขึ้น
  std::vector<size_t> s(k,eSize);
  for(size_t i = 0;i < (eSize * k) - mSize;i++){ // Calculate each stack size
    s[k - 1 - i]--;
  }
  output.resize(k); // resize output
  int cap = 0;
  for(size_t j = 0;j < k;j++){
    cap += s[j];
    for(size_t i = 0;i < s[j];i++){
      output[j].push(mData[mSize - cap + i]);
    }
  }
}

#endif
