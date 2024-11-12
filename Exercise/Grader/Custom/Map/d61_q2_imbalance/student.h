// Your code here
int my_recur(node* n, std::pair<int,KeyT> &tmp){
    int diff = 0,hl,hr;
    if(n->left != NULL && n->right != NULL){
        hl = 1 + my_recur(n->left,tmp);
        hr = 1 + my_recur(n->right,tmp);
    }else if(n->left != NULL && n->right == NULL){
        hl = 1 + my_recur(n->left,tmp);
        hr = -1;
    }else if(n->left == NULL && n->right != NULL){
        hl = -1;
        hr = 1 + my_recur(n->right,tmp);
    }else if(n->left == NULL && n->right == NULL) return -1;
    diff = abs(hl - hr);
    if(diff > tmp.first){
        tmp.second = (n->data).first;
        tmp.first = diff;
    }else if(diff == tmp.first){
        if((n->data).first < tmp.second){
            tmp.second = (n->data).first;
            tmp.first = diff;
        }
    }
    return hl>hr ? (hl):(hr);
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    if(mSize == 0) return (mRoot->data).first;
    std::pair<int,KeyT> res = {-1, (mRoot->data).first};
    my_recur(mRoot,res);
    return res.second;
}
