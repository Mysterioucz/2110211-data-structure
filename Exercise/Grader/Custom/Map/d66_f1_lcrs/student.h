// You may include library here
#include <algorithm>
int depth(node *n)
{
  // Write Code Here
  if(n == NULL) return -1;
  int curDepth = 0, nextDepth = 0;
  if(n->left_child != NULL){
    curDepth = depth(n->left_child) + 1;
  }
  if(n->right_sibling != NULL){
    nextDepth = depth(n->right_sibling);
  }
  return nextDepth > curDepth ? nextDepth:curDepth;
}