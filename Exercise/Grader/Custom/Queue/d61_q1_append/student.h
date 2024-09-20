#include "stack.h"
#include "queue.h"

namespace CP {
    template<typename T>
    void stack<T>::appendStack(stack<T> s) {
        ensureCapacity(mSize + s.size());
        mSize += s.size();
        for(size_t i = mSize - 1;i > (s.size() - 1);i--){
            mData[i] = mData[i-s.size()];// เลื่อนข้อมูล
        }
        for(size_t i = 0;i <= (s.size() - 1);i++){
            mData[i] = s.mData[i];
        }
    }

    template<typename T>
    void stack<T>::appendQueue(queue<T> q) {
       ensureCapacity(mSize + q.size());
       mSize += q.size();
       for(size_t i = mSize - 1;i > q.size() - 1;i--){
        mData[i] = mData[i - q.size()]; // เลื่อนข้อมูล
       }
       for(size_t i = 0;i < q.size();i++){
        mData[i] = q.mData[(q.size() - 1) - i]; // ใส่ข้อมูล
       }
    }

    template<typename T>
    void queue<T>::appendStack(stack<T> s) {
        ensureCapacity(mSize + s.size());
        mSize += s.size();
        for(size_t i = mSize - 1;i > mSize - s.size() - 1;i--){
            mData[i] = s.mData[(mSize - 1) - i];
        }
    }

    template<typename T>
    void queue<T>::appendQueue(queue<T> q) {
        while(!q.empty()){
            push(q.front());
            q.pop();
        }
    }
}
