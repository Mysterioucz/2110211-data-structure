#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    //your code here
    T val = mData[(mFront + pos)%mCap];
    pos = pos%mSize;
    for(int i = 0;i < pos;i++){
        int p = (mFront + pos - i)%mCap;
        if(p < 0) p = mCap - p;
        if(p == 0){
            mData[p] = mData[mCap - 1];
        }else{
            mData[p] = mData[p - 1];
        }
    }
    mData[mFront] = val;
}

#endif
