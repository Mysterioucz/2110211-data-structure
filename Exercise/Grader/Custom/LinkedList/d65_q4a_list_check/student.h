#ifndef __STUDENT_H__
#define __STUDENT_H__


template <typename T>
bool CP::list<T>::check() {
  //your code here
  int pos = 1;
  auto it = begin();
  node* prevPtr = mHeader;
  node* curPtr = begin().ptr;
  while(it != end()){
    if(it == NULL)return false;
    if(it.ptr->prev != prevPtr) return false;
    if(it.ptr != curPtr) return false;

    // Update value for next iteration
    prevPtr = it.ptr;curPtr = it.ptr->next;
    it++;pos++;
  }
  if(it.ptr->prev != prevPtr || it.ptr != curPtr || mSize != pos - 1) return false;
  return true;
}


#endif
