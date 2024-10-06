#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector-sm.h"
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void CP::vector_some_move<T>::insert(int index, std::vector<T> &value)
{
  // Your code here
  // First sol: Wrong in some case (don't even know why it's wrong) and Timeout
  // mSize += value.size();
  // ensureCapacity(mSize);
  // auto prev_cap = aux.end() - 2;
  // auto val = value.end() - 1;
  // long long row = mData.size() - 1;
  // long long s_pos = (mSize - 1) - value.size();
  // auto s_row = std::lower_bound(aux.begin(),aux.end(),s_pos);
  // auto s_prev_cap = s_row-1;
  // for(long long i = mSize - 1;i >= index;i--){
  //   if(i + 1 == *prev_cap ){
  //     if(prev_cap != aux.begin()){
  //       prev_cap--;
  //     }
  //     row--;
  //   }
  //   long long idx = i - *prev_cap;
  //   if(i < *prev_cap){ // ถ้า i มาอยู่ใน array เดียวกับ prev_cap แล้ว
  //     idx = i;
  //   }
  //   if((i >= index)&&(i <= index + value.size() -  1)){
  //     mData[row][idx] = *val;
  //     if(val != value.begin()){
  //       val--;
  //     }
  //   }else{
  //     if(s_pos + 1 == *s_prev_cap){
  //       if(s_prev_cap != aux.begin()){
  //       s_prev_cap--;
  //       }
  //       s_row--;
  //     }
  //     long long s_idx = s_pos - *s_prev_cap;
  //     if(s_pos < *s_prev_cap){ // ถ้า s_pos มาอยู่ใน array เดียวกับ s_prev_cap แล้ว
  //       s_idx = s_pos;
  //     }
  //     long long j = s_row - aux.begin();
  //     T ele = mData[j][s_idx];
  //     mData[row][idx] = ele;
  //     s_pos--;
  //   }
  // }
  int auxPos = std::upper_bound(aux.begin(), aux.end(), index) - aux.begin();
  if(auxPos > aux.size()) auxPos = aux.size();
  int prev_cap = auxPos == 0 ? 0:aux[auxPos - 1];
  if ((index == 0)||((prev_cap != 0)&&(prev_cap + 1 == index))||auxPos == aux.size())
  { // insert at front of this container
    mData.insert(mData.begin() + auxPos, value);
  }
  else
  {
    std::vector<T> temp;
    temp = mData[auxPos];
    std::vector<std::vector<T>> ins;
    // mData.erase(mData.begin() + auxPos);
    int pos = auxPos == 0 ? index : (index - aux[auxPos - 1]);
    std::vector<T> temp1(temp.begin(), temp.begin() + pos), temp2(temp.begin() + pos, temp.end());
    ins.push_back(temp1);
    ins.push_back(value);
    // ins.push_back(temp2);
    mData[auxPos] = temp2;
    mData.insert(mData.begin() + auxPos, ins.begin(), ins.end());
  }
  aux.resize(mData.size());

  while (auxPos < aux.size())
  {
    if (auxPos != 0)
    {
      aux[auxPos] = mData[auxPos].size() + aux[auxPos - 1];
    }
    else
    {
      aux[auxPos] = mData[auxPos].size();
    }
    auxPos++;
  }
  mSize += value.size();
  mCap += value.size();
}

#endif