#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

// you can modify and use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,size_t level,size_t tmp,std::vector<KeyT> &v) {
  //you MAY need to use this function
  //Traversal by go to right child first
  if(n == NULL) return;
  if(tmp < level){
    if(n->right != NULL) my_recur(n->right,level,tmp + 1,v);
    if(n->left != NULL) my_recur(n->left,level,tmp + 1,v);
    
  }else if(tmp == level){
    v.push_back(n->data.first);
  }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
std::vector<KeyT> CP::map_bst<KeyT,MappedT,CompareT>::at_level(size_t level) {
  //write your code here
  std::vector<KeyT> result;
  my_recur(mRoot, level, 0, result);
  // std::sort(result.rbegin(),result.rend(),mLess);
  return result;
}


#endif
