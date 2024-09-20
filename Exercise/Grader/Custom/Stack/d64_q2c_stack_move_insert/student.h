#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
void CP::stack<T>::moveInsert(int k,CP::stack<T> &s2, int m) {
  //your code here
  int insPos = (mSize - 1) - k;
  insPos = insPos < -1 ?-1:insPos;
  m = m > s2.mSize ? s2.mSize:m;
  if(mSize + m > mCap){
    size_t newCap = mSize + m > 2*mCap ? mSize+m:2*mCap;
    expand(newCap);
  }
  mSize += m;
  for(long long i = mSize - 1;i > insPos + m;i--){
    mData[i] = mData[i-m]; // เลื่อนข้อมูล 
  }
  for(long long i = insPos + m;i > insPos;i--){
    int pos = (s2.mSize - 1) - ((insPos + m) - i);
    mData[i] = s2.mData[pos]; // insert ข้อมูลจากอีก Stack
  }
  s2.mSize -= m;
}
#endif
