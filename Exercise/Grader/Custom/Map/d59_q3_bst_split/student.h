#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* curNode = mRoot;
  node* lastNode = NULL;
  node* lastRes = NULL;
  bool status = false;
  mRoot = NULL;
  while(curNode != NULL){
    if(curNode->data.first >= val){
      if(!status){
        if(curNode->parent != NULL) curNode->parent->right = NULL;
        if(lastRes == NULL){
          result.mRoot = curNode;
          curNode->parent = NULL;
        }else{
          lastRes->left = curNode;
          curNode->parent = lastRes;
        }
        status = true;
      }
      lastRes = curNode;
      curNode = curNode->left;
    }else{
      if(status){
        if(curNode->parent != NULL) curNode->parent->left = NULL;
        if(lastNode == NULL){
          mRoot = curNode;
          lastNode = curNode;
          curNode->parent = NULL;
        }else{
          lastNode->right = curNode;
          curNode->parent = lastNode;
        }
        status = false;
      }
      if(lastNode == NULL){
          mRoot = curNode;
      }
      lastNode = curNode;
      curNode = curNode->right;
    }
  }
  return result;
}

#endif
