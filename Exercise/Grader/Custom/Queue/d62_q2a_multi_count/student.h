#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <map>

template <typename T>
std::vector<std::pair<T,size_t>> CP::queue<T>::count_multi(std::vector<T> &k) const {
    //write your code here
    using namespace std;
    map<T,size_t> freq;
    vector<pair<T,size_t>> res;
    for(size_t i = 0;i < mSize;i++){
        freq[mData[(mFront + i)%mCap]]++;
    }
    for(auto e:k){
        res.push_back({e,freq[e]});
    }
    return res;

}

#endif
