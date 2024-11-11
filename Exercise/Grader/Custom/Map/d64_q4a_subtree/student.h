#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT,typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT,MappedT,CompareT>::process(node* n) {
  //write your code here
  if(n->left == NULL && n->right == NULL){
    return 1;
  }else if(n->left != NULL && n->right != NULL){
    return process(n->left) + process(n->right) + 1;
  }else if(n->left != NULL){
    return process(n->left) + 1;
  }else if(n->right != NULL){
    return process(n->right) + 1;
  }
  return 0;
}

template <typename KeyT,typename MappedT, typename CompareT >
std::pair<KeyT,MappedT> CP::map_bst<KeyT,MappedT,CompareT>::subtree(map_bst<KeyT,MappedT,CompareT> &left, map_bst<KeyT,MappedT,CompareT> &right) {
  //write your code here
  if(mRoot == NULL || mSize == 0)return std::pair<KeyT,MappedT>();
  if(mRoot->left != NULL){
    mRoot->left->parent  = NULL;
    left.mRoot = mRoot->left;
    left.mSize = process(left.mRoot);
    mRoot->left = NULL;
  }
  if(mRoot->right != NULL){
    mRoot->right->parent  = NULL;
    right.mRoot = mRoot->right;
    right.mSize = process(right.mRoot);
    mRoot->right = NULL;
  }
  mSize = 1;
  return std::pair<KeyT,MappedT>(mRoot->data.first,mRoot->data.second);
}

#endif

