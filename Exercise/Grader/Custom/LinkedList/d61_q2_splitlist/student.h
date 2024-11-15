void splitList(list<T> &list1, list<T> &list2)
{
    // Add your code here
    if (mSize == 1)
    {
        list1.mHeader->next = mHeader->next;
        mHeader->next->prev = list1.mHeader;
        mHeader->next = mHeader;
        mHeader->prev = mHeader;
    }
    else if (mSize > 1)
    {
        node *start_a = mHeader->next;
        node *end_a = mHeader;
        node *start_b = mHeader;
        node *end_b = mHeader->prev;

        int rnd = mSize - (mSize / 2);
        for (int i = 0; i < rnd; i++)
        {
            end_a = end_a->next;
        }
        start_b = end_a->next;

        list1.mHeader->next = start_a;
        start_a->prev = mHeader;
        list1.mHeader->prev = end_a;
        start_b->prev = mHeader;
        list2.mHeader->next = start_b;
        end_b->next = mHeader;
        list2.mHeader->prev = end_b;
        end_a->next = mHeader;
        list1.mSize = rnd;
        list2.mSize = mSize - rnd;
    }
    mHeader->prev = mHeader;
    mHeader->next = mHeader;
    mSize = 0;
}
