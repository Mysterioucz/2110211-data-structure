#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <cmath>
#include <algorithm>

template <typename T>
std::vector<std::vector<T>> CP::stack<T>::distribute(size_t k) const {
  //write your code here
  using std::vector;
  size_t eSize = ceil((mSize + 0.0)/(k + 0.0)), j = 0;
  vector<size_t> arr(k,eSize);
  // int lim = k-2, pos = k-1;
  for(int i = 0;i < (eSize*k - mSize);i++){ // Loop นี้ไม่มีทางรันเกิน k รอบ
    arr[(k-1-i)]--; 
  }
  vector<vector<T>> res(k);
  for(long long i = mSize-1; i >= 0;i--){ // 0 1 2 3 4 5 6 7
    res[j].push_back(mData[i]);
    long long check = ((long long)res[j].size() + 1) - (i);
    if(res[j].size() == arr[j]){
      j++;
    }
  }
  return res;
}
#endif
