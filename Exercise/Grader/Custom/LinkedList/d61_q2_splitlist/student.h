void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if(mSize == 0) return;
    int c = 1;
    auto it = begin();

    // List 1
    it.ptr->prev = list1.mHeader->prev;
    list1.mHeader->prev->next = it.ptr;
    while(c < (mSize + 1)/2){
        it++;c++;
    }
    auto tmp = it;it++;c++;
    tmp.ptr->next = list1.mHeader;
    list1.mHeader->prev = tmp.ptr;
    list1.mSize += (mSize + 1)/2;

    // List 2
    it.ptr->prev = list2.mHeader->prev;
    list2.mHeader->prev->next = it.ptr;
    mHeader->prev->next = list2.mHeader;
    list2.mHeader->prev = mHeader->prev;
    list2.mSize += mSize - (mSize + 1)/2;

    // Current List clear
    mHeader->next = mHeader;
    mHeader->prev = mHeader;
    mSize = 0;
}