#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::my_recur(node* n,int level,int tmp) {
    //you MAY need to use this function
    if(n == NULL) return;
    my_recur(n->left,level,tmp + 1);
    my_recur(n->right,level,tmp + 1);
    if(tmp > level){
        if(n->parent != NULL){
            if(n->parent->left == n) n->parent->left = NULL;
            else if(n->parent->right == n) n->parent->right = NULL;    
        }
        if(n == mRoot){
            mRoot = NULL;
        }
        delete n;
        mSize--;
    }
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
void CP::map_bst<KeyT,MappedT,CompareT>::trim(int depth) {
	/*write your code here
    If you cry on seeing the question, it is an insult. 
    If your teacher cries upon seeing your answer submission, 
    it is your achievement.

    Good luck with final and see you in Algorithm Design.
    */
   my_recur(mRoot,depth,0);

}

#endif
