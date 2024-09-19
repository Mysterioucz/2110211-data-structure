#ifndef __STUDENT_H_
#define __STUDENT_H_

// #include <queue>
#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  // First sol: slow insert
  // std::priority_queue<std::pair<int,T>,std::vector<std::pair<int,T>>,std::greater<std::pair<int,T>>> pq;
  // for(size_t i = 0;i < data.size();i++){
  //   pq.push(data[i]);
  // }
  // int count = 0;
  // while(!pq.empty()){
  //   std::pair<int,T> top = pq.top();
  //   int pos = top.first;
  //   T e = top.second;
  //   insert(&mData[0] + (pos + count),e);
  //   pq.pop();
  //   count++;
  // }
  sort(data.begin(),data.end());
  int min = data[0].first,tIndex = data.size()-1,count = data.size()-1;
  ensureCapacity(mSize + data.size());
  for(int i = mSize + data.size() - 1;i >=min;i--){
    if(i == data[tIndex].first + count){
      mData[i] = data[tIndex].second;
      count--;
      tIndex--;
    }else{
      mData[i] = mData[i-count-1];
    }
  }
  mSize += data.size();
}

#endif
