#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <queue>
#include <vector>

template <typename T,typename Comp >
bool CP::priority_queue<T,Comp>::operator==(const CP::priority_queue<T,Comp> &other) const {

  //write your code here
  if(mSize == other.mSize){
    std::priority_queue<T,std::vector<T>,Comp> pq1(mLess);
    std::priority_queue<T,std::vector<T>,Comp> pq2(other.mLess);
    for(size_t i = 0;i < mSize;i++){
      pq1.push(mData[i]);
      pq2.push(other.mData[i]);
    }
    while(!pq1.empty()&&!pq2.empty()){
      if(pq1.top() != pq2.top()) return false;
      pq1.pop();pq2.pop();
    }
    return true;
  }
  return false; // you can change this line
}

#endif
