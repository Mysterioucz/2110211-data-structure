#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
int CP::stack<T>::compare_reserve(const CP::stack<T> &other) const {
    //write your code here
    long long spaceLeft = (mCap - mSize) - (other.mCap - other.mSize);
    return spaceLeft < 0 ? -1:spaceLeft!=0; // ถ้า พื้นที่ที่สำรองน้อยกว่า return -1 ถ้าเท่ากัน return 0 (false) มากกว่า return 1 (true)
}

#endif
