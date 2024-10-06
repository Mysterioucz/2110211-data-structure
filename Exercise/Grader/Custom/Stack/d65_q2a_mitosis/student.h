#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    int amount = b - a + 1,j = mSize - 1;
    if (mSize + amount > mCap)expand(mCap * 2);
    mSize += amount;
    int start = (mSize - 1) - a,stop = (mSize - 1) - (b + amount);
    for(long long i = mSize-1;i >= stop;i--){
        mData[i] = mData[j];
        if((stop <= i)&&(i <= start)){
            if((start - i)%2 == 1){
                j--;
            }
        }else{
            j--;
        }
    }
}

#endif