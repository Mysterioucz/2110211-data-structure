#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <vector>

template <typename T>
void CP::vector<T>::range_erase(std::vector<std::pair<iterator, iterator>> &ranges) {
  // Write code here
  std::vector<int> check(mSize,0);
  for(auto p:ranges){
    check[p.first - begin()] += 1;
    if((p.second - begin()) < mSize){
      check[p.second - begin()] -= 1;
    }
  }
  int i = 0,j = 0,k = 0;
  while (i < mSize){
    k += check[i];
    if(k==0){ // k==0 mean it's not been erased
      mData[j] = mData[i];
      j++;// j ระบุถึงตำแหน่งใหม่จะเพิ่มขึ้นเฉพาะตอนที่ช่องนั้นไม่ได้ถูกลบ
    }
    i++; // i ไล่ไปทุกตัวใน mData
  }
  mSize = j;
}

#endif
