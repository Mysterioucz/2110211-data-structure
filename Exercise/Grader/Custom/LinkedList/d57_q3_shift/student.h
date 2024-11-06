void shift(int k) {
	// TODO: Add your code here
	int c = 1;
	CP::list<T>::iterator it;
	if(k > 0){
		k = k%mSize;
		if(k == 0) return;
		it = begin();
		while(c!=k){
			it++;
			c++;
		}
	}else{
		k = (k*-1)%mSize;
		if(k == 0) return;
		it = (--end());
		while(c!=k + 1){
			it--;
			c++;
		}
	}
	mHeader->prev->next = begin().ptr;
	begin().ptr->prev = mHeader->prev;
	it.ptr->next->prev = mHeader;
	mHeader->next = it.ptr->next;
	it.ptr->next = mHeader;
	mHeader->prev = it.ptr;

}
