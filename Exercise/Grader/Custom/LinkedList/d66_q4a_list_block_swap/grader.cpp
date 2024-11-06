#include "list.h"
#include "student.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::string;


template <typename T>
void create_list() {
	string KEY = "gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m";
	int ableToCreateNode, N;
	cin >> ableToCreateNode >> N;

	CP::list<T > l;
	l.setAbleToCreateNode(true, KEY);
	auto it = l.begin(), a1 = l.begin(), a2 = l.begin(), b1 = l.begin(), b2 = l.begin();

	for(int i=0;i<N;i++){
		T val;
		cin >> val;
		l.push_back(val);
	}
	l.setAbleToCreateNode(false, KEY);

	int Q;
	cin >> Q;
	int i1, i2, j1, j2;
	while(Q--) {
		cin >> i1 >> i2 >> j1 >> j2;
		
		it = l.begin();
		for(int i=0;i<=N;i++){
			if(i == i1)	a1 = it;
			if(i == i2)	a2 = it;
			if(i == j1)	b1 = it;
			if(i == j2)	b2 = it;
			it++;
		}
		
		if (ableToCreateNode == 0)
			l.setAbleToCreateNode(false, KEY);
		else
			l.setAbleToCreateNode(true, KEY);

		l.block_swap(a1, a2, b1, b2);

		l.setAbleToCreateNode(false, KEY);

		l.print();
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int type;
	cin >> type;

	if(type == 0)
		create_list<int >();
	if(type == 1)
		create_list<string>();

	cout << "\nKEY: gEliyXy1WsQBUpm8EO2nK2HHUJt7Hu0m";
}