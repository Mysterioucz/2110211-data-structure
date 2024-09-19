#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
#include <set>
#include <vector>
using namespace std;
//you are allow to use any data structure


template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  set<T> s; // maybe using unordered is better? (because we not need another vector)
  vector<T> v;
  for(auto it = &mData[0];it < (&mData[0] + mSize);it++){
    if(s.find(*it) == s.end()){
      s.insert(*it);
      v.push_back(*it);
    }
  }
  for(size_t i = 0;i < v.size();i++){
    mData[i] = v[i];
  }
  mSize = v.size();
}

#endif
