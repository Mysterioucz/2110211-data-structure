#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"
#include <vector>
#include <algorithm>

template <typename T>
void CP::stack<T>::reverse(size_t first, size_t last){
	// write your code here
	if((first <= last)&&(mSize != 0)){
		first = std::max(0, (int)first);
		last = std::min(mSize - 1, last);
		std::vector<T> temp;
		for(int i = last; i >= (int)first;i--){
			temp.push_back(mData[(mSize - 1) - i]);
		}
		int i = temp.size() - 1, j = (mSize - 1) - last;
		while(i >= 0){
			mData[j] = temp[i];
			i--;j++;
		}
	}
}

#endif
