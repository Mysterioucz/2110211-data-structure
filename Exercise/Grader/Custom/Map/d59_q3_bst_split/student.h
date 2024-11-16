#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here


  CP::map_bst<KeyT,MappedT,CompareT> result;
  node* n = mRoot;
  node* fNode = NULL;
  node* sNode = NULL;
  node* tNode = NULL;
  node* par_fNode = NULL;
  node* par_sNode = NULL;
  while(n != NULL){
    if(n->data.first < val && fNode == NULL){
      n = n->right;
    }else{
      if(fNode == NULL){
        fNode = n;
        par_fNode = fNode->parent;
      }
      if(n->data.first >= val && sNode == NULL) n = n->left;
      else {
        if(sNode == NULL){
          sNode = n;
          par_sNode = sNode->parent;
        }
        if(n->data.first < val && tNode == NULL) n = n->right;
        else if(tNode == NULL){
          tNode = n; break;
        }
      }
    }
  }
  if(fNode != NULL){
    result.mRoot = fNode;
    if(par_fNode != NULL){
      fNode->parent = NULL;
      par_fNode->right = sNode;
    }else{
      mRoot = NULL;
    }
    if(sNode != NULL){
      sNode->parent = par_fNode;
      if(par_fNode == NULL){ // Check in case that fNode is mRoot then sNode is the new mRoot of Current BST
        mRoot = sNode;
      }
      par_sNode->left = tNode;
      if(tNode != NULL){
        tNode->parent->right = NULL;
        tNode->parent = par_sNode;
    }
    }

  }

  return result;
}

#endif
