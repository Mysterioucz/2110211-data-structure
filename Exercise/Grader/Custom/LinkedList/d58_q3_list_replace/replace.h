
void replace(const T& x, CP::list<T>& y) {
  //write your code here
  for(CP::list<T>::iterator it = begin();it != end();it++){
    if(*it == x){ // if current node.data is equal to x
      it = erase(it); // erase it
      for(CP::list<T>::iterator it2 = y.begin(); it2 != y.end();it2++){ // insert it with new element from y
        it = insert(it,*it2);
        if(it2 != --y.end())it++; // goes to next node because insert return iterator that point to inserted node but insert() insert a node before iterator
        
      }
    }
  }
}
