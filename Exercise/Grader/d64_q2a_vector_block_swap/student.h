#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here
  T *begin = &mData[0];
  T *end = &mData[0] + mSize;
  if((a >= begin)&&((a+m-1)<end)&&(b >= begin)&&(b+m-1 < end)&&!((b <= a)&&(a <= b+m-1))&&!((b <= a+m-1)&&(a+m-1 <= b+m-1))&&(m > 0)){
    for(int i = 0;i < m;i++){
      T c = *(a+i);
      *(a+i) = *(b+i);
      *(b+i) = c;
    }
    return true;
  }
  return false;
}

#endif
