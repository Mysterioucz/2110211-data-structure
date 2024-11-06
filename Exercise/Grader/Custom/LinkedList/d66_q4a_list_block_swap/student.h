#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "list.h"

template <typename T>
void CP::list<T>::block_swap(iterator a1, iterator a2, iterator b1, iterator b2) {
	// write your code here
	if(a1==a2 && b1==b2)return;
	else if(a1==a2 && b1!=a2){
		auto tmp1 = b1.ptr, tmp2 = b2.ptr->prev;
		b2.ptr->prev = b1.ptr->prev;
		b1.ptr->prev->next = b2.ptr;

		a1.ptr->prev->next = tmp1;
		tmp1->prev = a1.ptr->prev;
		a1.ptr->prev = tmp2;
		tmp2->next = a1.ptr;
	}else if(b1==b2 && a1!=a2){
		auto tmp1 = a1.ptr, tmp2 = a2.ptr->prev;
		a2.ptr->prev = a1.ptr->prev;
		a1.ptr->prev->next = a2.ptr;

		b1.ptr->prev->next = tmp1;
		tmp1->prev = b1.ptr->prev;
		b1.ptr->prev = tmp2;
		tmp2->next = b1.ptr;
	}else if((a1 != a2)&&(b1 != b2)){
		node* tmp1 = a2.ptr->prev; 
		node* tmp2 = b2.ptr->prev;
		a1.ptr->prev->next = b1.ptr;
		b1.ptr->prev->next = a1.ptr;

		b2.ptr->prev = (tmp1);
		a2.ptr->prev = (tmp2);

		if(a1 != b2){
			tmp1->next = b2.ptr;
			a1.ptr->prev = b1.ptr->prev;
		}
		else{
			tmp1->next = b1.ptr;
			a1.ptr->prev = tmp2;
		}
		if(a2 != b1){
			tmp2->next = a2.ptr;
			b1.ptr->prev = a2.ptr;
		}
		else{
			tmp2->next = a1.ptr;
			b1.ptr->prev = tmp1;
		}
		}
	mHeader->next->prev = mHeader;
	mHeader->prev->next = mHeader;
}

#endif
