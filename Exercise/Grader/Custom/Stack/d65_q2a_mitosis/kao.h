#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    int c = 0;
    CP::stack<T> info;
    if((b - a) + mSize > mCap){
        expand(2*mCap);
    }
    while (c<b) {
        info.push(top());
        pop();
        c++;
    }
    push(top());
    while (c>a) {
        push(info.top());
        push(info.top());
        info.pop();
        c--;
    }
    while (!info.empty()) {
        push(info.top());
        info.pop();
    }
}

#endif 