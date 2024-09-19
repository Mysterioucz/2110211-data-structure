#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress() {
    //write your code here
    // Back up previous value
    T *pData = mData;
    // Update value
    mData = new T[mSize];
    mCap = mSize; // Update Capacity of dynamic array
    for(size_t i = 0;i < mSize;i++){
        mData[i] = pData[i];
    }
    delete [] pData;// Delete old values
}

#endif
