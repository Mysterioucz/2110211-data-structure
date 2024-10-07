#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::pop() {
	// modify method here
	if(stack_a.empty()&&stack_b.empty()){
		return;
	}
	if(stack_a.empty()){
		size_t s = stack_b.size();
		std::stack<T> temp;
		while(stack_b.size() > (s + 1)/2){
			temp.push(stack_b.top());
			stack_b.pop();
		}
		while(!stack_b.empty()){
			stack_a.push(stack_b.top());
			stack_b.pop();
		}
		while(!temp.empty()){
			stack_b.push(temp.top());
			temp.pop();
		}
	}
	stack_a.pop();
}

template <typename T>
const T& CP::stack<T>::top() {
	// modify method here
	if(stack_a.empty()){
		size_t s = stack_b.size();
		std::stack<T> temp;
		while(stack_b.size() > (s + 1)/2){
			temp.push(stack_b.top());
			stack_b.pop();
		}
		while(!stack_b.empty()){
			stack_a.push(stack_b.top());
			stack_b.pop();
		}
		while(!temp.empty()){
			stack_b.push(temp.top());
			temp.pop();
		}

	}
	return stack_a.top();
	
}

template <typename T>
const T& CP::stack<T>::bottom() {
	// write your code here
	if(stack_b.empty()){
		size_t s = stack_a.size();
		std::stack<T> temp;
		while(stack_a.size() > (s + 1)/2){
			temp.push(stack_a.top());
			stack_a.pop();
		}
		while(!stack_a.empty()){
			stack_b.push(stack_a.top());
			stack_a.pop();
		}
		while(!temp.empty()){
			stack_a.push(temp.top());
			temp.pop();
		}
	}
	return stack_b.top();
}

template <typename T>
void CP::stack<T>::push_bottom(const T& element) {
	// write your code here
	stack_b.push(element);
}

template <typename T>
void CP::stack<T>::pop_bottom() {
	// write your code here
	if(stack_a.empty()&&stack_b.empty()){
		return;
	}
	if(stack_b.empty()){
		size_t s = stack_a.size();
		std::stack<T> temp;
		while(stack_a.size() > (s + 1)/2){
			temp.push(stack_a.top());
			stack_a.pop();
		}
		while(!stack_a.empty()){
			stack_b.push(stack_a.top());
			stack_a.pop();
		}
		while(!temp.empty()){
			stack_a.push(temp.top());
			temp.pop();
		}
	}
	stack_b.pop();
}
#endif