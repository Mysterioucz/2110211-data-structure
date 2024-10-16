#ifndef __STUDENT_H_
#define __STUDENT_H_

//can include anything
#include <algorithm>
#include <vector>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos,CompareT  comp) {
  // Write code here
  // you can compare two data A and B of type T by calling comp(A,B)
  // which return true when A is less than B
  vector<int> p;
  for(auto it:pos){
    p.push_back(it - begin());
  }
  std::sort(p.begin(),p.end());
  std::vector<T> temp;
  for(auto it:pos){
    temp.push_back(*it);
  }
  std::sort(temp.begin(),temp.end(),comp);
  for(int i = 0;i < temp.size();i++){
    mData[p[i]] = temp[i];
  }
}

#endif
