#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	// write your code here
	// TODO FIX THIS
	if(a1==a2 && b1==b2)return;
	if(b1 == a2){
		std::swap(a1,b1);
		std::swap(a2,b2); // if a1==b2 this will broke
	}
	if(a1 == b2){
		auto a_prev = a1.ptr->prev;
    	auto b_prev = b1.ptr->prev;
    	auto a_end = a2.ptr->prev;
    	auto b_end = b2.ptr->prev;

    	// Adjust pointers for swapping ranges `[a1, a2)` and `[b1, b2)`
    	a_prev->next = a2.ptr; // fixed
    	b_prev->next = a1.ptr;
    	b_end->next = a2.ptr;
    	a_end->next = b1.ptr;

    	// Adjust `prev` pointers
    	a1.ptr->prev = b_prev;
    	b1.ptr->prev = a_end;
    	a2.ptr->prev = b_end;
	}else{
		std::swap(a1.ptr->prev->next,b1.ptr->prev->next);
		std::swap(a1.ptr->prev,b1.ptr->prev); // if a1==b2 this will broke
		std::swap(a2.ptr->prev->next,b2.ptr->prev->next);
		std::swap(a2.ptr->prev,b2.ptr->prev);
	}
	
}
#endif
