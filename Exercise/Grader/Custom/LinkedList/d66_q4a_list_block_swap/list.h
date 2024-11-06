#ifndef _CP_LIST_INCLUDED_
#define _CP_LIST_INCLUDED_

#include <stdexcept>
#include <iostream>
//#pragma once

bool ableToCreateNode_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m = false;
int numberOfListCreated_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m = 0;

namespace CP {

template <typename T>
class list
{
  protected:
    class node {
      friend class list;
      public:
        T data;
        node *prev;
        node *next;

        node() :
          data( T() ), prev( this ), next( this ) {
			  if (numberOfListCreated_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m != 0 && ableToCreateNode_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m == false) {
				throw std::out_of_range("can't create node");
			  }
		  }

        node(const T& data,node* prev, node* next) :
          data ( T(data) ), prev( prev ), next( next ) {
			  if (numberOfListCreated_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m != 0 && ableToCreateNode_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m == false) {
				throw std::out_of_range("can't create node");
			  }
		  }
    };

    class list_iterator {
      friend class list;
      protected:
        node* ptr;
      public:

        list_iterator() : ptr( NULL ) { }

        list_iterator(node *a) : ptr(a) { }

        list_iterator& operator++() {
          ptr = ptr->next;
          return (*this);
        }

        list_iterator& operator--() {
          ptr = ptr->prev;
          return (*this);
        }

        list_iterator operator++(int) {
          list_iterator tmp(*this);
          operator++();
          return tmp;

        }
        list_iterator operator--(int) {
          list_iterator tmp(*this);
          operator--();
          return tmp;
        }

        T& operator*() { return ptr->data; }
        T* operator->() { return &(ptr->data); }
        bool operator==(const list_iterator& other) { return other.ptr == ptr; }
        bool operator!=(const list_iterator& other) { return other.ptr != ptr; }
    };

  public:
    typedef list_iterator iterator;

  protected:
    node *mHeader; // pointer to a header node
    size_t mSize;


  public:
    //-------------- constructor & copy operator ----------

    // copy constructor
    list(const list<T>& a ) :
      mHeader( new node() ), mSize( 0 ) {
      for (auto &x : *this) {
        push_back(x);
      }
	  numberOfListCreated_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m++;
    }

    // default constructor
    list() :
      mHeader( new node() ), mSize( 0 ) {
		numberOfListCreated_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m++;
	  }

    // copy assignment operator using copy-and-swap idiom
    list<T>& operator=(list<T> other) {
      // other is copy-constructed which will be destruct at the end of this scope
      // we swap the content of this class to the other class and let it be descructed
      using std::swap;
      swap(this->mHeader, other.mHeader);
      swap(this->mSize, other.mSize);
      return *this;
    }

    ~list() {
      clear();
      delete mHeader;
    }

    //------------- capacity function -------------------
    bool empty() const {
      return mSize == 0;
    }

    size_t size() const {
      return mSize;
    }


    //----------------- iterator ---------------
    iterator begin() {
      return iterator(mHeader->next);
    }

    iterator end() {
      return iterator(mHeader);
    }
    //----------------- access -----------------
    T& front() { return mHeader->next->data; }

    T& back() { return mHeader->prev->data; }

    //----------------- modifier -------------
    void push_back(const T& element) {
      insert(end(),element);
    }

    void push_front(const T& element) {
      insert(begin(),element);
    }

    void pop_back() {
      erase(iterator(mHeader->prev));
    }

    void pop_front() {
      erase(begin());
    }

    iterator insert(iterator it,const T& element) {
	  if (ableToCreateNode_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m == false) {
		throw std::out_of_range("can't create node");
	  }
      node *n = new node(element,it.ptr->prev, it.ptr);
      it.ptr->prev->next = n;
      it.ptr->prev = n;
      mSize++;
      return iterator(n);
    }

    iterator erase(iterator it) {
      iterator tmp(it.ptr->next);
      it.ptr->prev->next = it.ptr->next;
      it.ptr->next->prev = it.ptr->prev;
      delete it.ptr;
      mSize--;
      return tmp;
    }

    void clear() {
      while (mSize > 0) erase(begin());
    }

    void print() {
      for (iterator it = begin();it!=end(); it++) {
        std::cout << it.ptr->data << " ";
      }

	  std::cout << "\n";

      iterator it = end();
	  for (it--;it!=end(); it--) {
		  std::cout << it.ptr->data << " ";
	  }

	  std::cout << "\n";
    }

	//-------------- For grader --------------
	void setAbleToCreateNode(bool value, std::string key) {
		if(key == "gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m")
			ableToCreateNode_gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m = value;
		else
			throw std::out_of_range("wrong key");
	}

	//-------------- For student.h --------------
	void block_swap(iterator a1, iterator a2, iterator b1, iterator b2);

};

}

#endif

