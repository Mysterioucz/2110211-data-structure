#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "priority_queue.h"
#include <iostream>


template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixUp(size_t idx) {
    T tmp = mData[idx];
    while ( idx > 0){
        size_t p = (idx - 1)/4;
        if(mLess(tmp,mData[p])) break;
        mData[idx] = mData[p];
        idx = p;
    }
    mData[idx] = tmp;
}

template <typename T,typename Comp >
void CP::priority_queue<T,Comp>::fixDown(size_t idx) {
    T tmp = mData[idx];
    size_t c;
    while((c = 4*idx+1) < mSize){
        size_t max_c = c;
        for(int i = 1;i < 4;i++){
            if((c + i < mSize)&&(mLess(mData[max_c],mData[c + i]))){
                max_c = c+i;
            }
        }
        c = max_c;
        if(mLess(mData[c],tmp)) break;
        mData[idx] = mData[c];
        idx = c;
    }
    mData[idx] = tmp;
}

#endif

