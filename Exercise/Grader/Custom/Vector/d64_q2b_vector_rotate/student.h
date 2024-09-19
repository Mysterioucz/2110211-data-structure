#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k)
{
  // write your code here
  // First Sol: time out
  // while (k--)
  // {
  //   T pFirst = *first;
  //   for (iterator i = first; i != last - 1; i++)
  //   {
  //     *i = *(i + 1);
  //   }
  //   *(last - 1) = pFirst;
  // }
  std::vector<T> v(first,last);
  iterator begin = &mData[0];
  for (iterator i = first; i != last; i++){
    size_t index = ((i-begin)+ k - (first - begin))%(last - first);
    *i = v[index];
  }
}

#endif
