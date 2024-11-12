#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

//you can use this function
template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf(node* n) {
  if(n == NULL) return 0;
  if(n->left != NULL && n->right != NULL){
    return std::min(1 + shallowest_leaf(n->left), 1 + shallowest_leaf(n->right));
  }else if(n->left != NULL && n->right == NULL){
    return 1 + shallowest_leaf(n->left);
  }else if(n->left == NULL && n->right != NULL){
    return 1 + shallowest_leaf(n->right);
  }
  return 0; // Case n is leaf
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT,MappedT,CompareT>::shallowest_leaf() {
  //write your code here
  if(mSize == 0) return -1;
  else if(mSize == 1) return 0;
  return shallowest_leaf(mRoot);
}


#endif
