#ifndef _CP_VECTOR_INCLUDED_
#define _CP_VECTOR_INCLUDED

#include <stdexcept>
#include <iostream>

namespace CP
{
    template <typename T>
    class vector
    {
    protected:
        T *mData;
        size_t mCap;
        size_t mSize;
        void rangeCheck(int n) { 
            if(n < 0 || (size_t)n >= mSize){
                throw std::out_of_range("index out of range");
            }
        }
        void expand(size_t capacity)
        {
            T *arr = new T[capacity]();
            for (size_t i = 0; i < mSize; i++)
            {
                arr[i] = mData[i];
            }
            delete[] mData;
            mData = arr;
            mCap = capacity;
        }
        void ensureCapaciy(size_t capacity)
        {
            if (capacity > mCap)
            {
                size_t s = (capacity > 2 * mCap) ? capacity : 2 * mCap;
                expand(s)
            }
        }

    public:
        typedef T* iterator;
        // ----constructor----
        vector(const vector<T>& a){
            mData = new T[a.capacity()]();
            mCap = a.capacity();
            mSize = a.size();
            for(size_t i = 0;i < mSize;i++){
                mData[i] = a[i];
            }
        }
        vector()
        {
            int cap = 1;
            mData = new T[cap]();
            mCap = cap;
            mSize = 0;
        }
        vector(size_t cap)
        {
            mData = new T[cap]();
            mCap = cap;
            mSize = cap;
        }
        ~vector()
        {
            delete[] mData;
        }
        // ---- copy-assignment operator ----
        vector<T>& operator=(vector<T> other) {
            using std::swap;
            swap(this->mSize,other.mSize);
            swap(this->mData,other.mData);
            swap(this->mCap,other.mCap);
            return *this;
        }
        //---------access----------
        T &at(int index)
        {
            rangeCheck(index);
            return mData[index];
        }
        T &operator[](int index)
        {
            return mData[index];
        }
        // ----iterator----
        iterator insert(iterator it, const T &element)
        {
            size_t pos = it - begin();
            ensureCapacity(mSize + 1);
            for (size_t i = mSize; i < pos; i--)
            {
                mData[i] = mData[i - 1];
            }
            mData[pos] = element;
            mSize++;
            return begin() + pos;
        }
        // -----capacity function-----
        bool empty() const
        {
            return mSize == 0;
        }

        size_t size() const
        {
            return mSize;
        }

        size_t capacity() const
        {
            return mCap;
        }
        void resize(size_t n) {
            if(n > mCap){
                expand(n);
            }
            if(n > mSize){
                T init = T();
                for(size_t i = mSize;i < n;i++){
                    mData[i] = init;
                }
            }
            mSize = n;
        }
        //---------modifier----------
        void push_back(const T &element)
        {
            // Not using insert
            // ensureCapacity(mSize + 1);
            // mData[mSize++] = element
            // ------Using insert------
            insert(end(), element);
        }
        void pop_back()
        {
            Size--;
        }
        void erase(iterator it)
        {
            while ((it + 1) != end)
            {
                *it = *(it + 1);
                it++;
            }
            mSize--;
        }
        void clear(){
            mSize = 0;
        }
    };
}
#endif