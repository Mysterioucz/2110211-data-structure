#include <iostream>
#include <string>
#include "map_bst.h"
#include "student.h"
template <typename T>
void sol(){
    std::string KEY = "523252TTelgniSsIrettoPyhW";
    int canCreate, N , K;
    std::cin >> canCreate >> N >> K;

    CP::map_bst<T,int> m;
    m.setAbleToCreateNode(true,KEY);
    for(int i = 0 ; i < N ; ++i){
        T val;
        std::cin >> val;
        m[val] = i;
    }
    m.setAbleToCreateNode(canCreate,KEY);
    m.print();
    while(K--){
        int depth;
        std::cin >> depth;
        m.trim(depth);
        m.print();
        std::cout << "Delete node count = "<< m.getDeleteNodeCount() << '\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    int type;
    std::cin >> type;
    if(type == 0)
		sol<int >();
	if(type == 1)
		sol<std::string>();
    std::cout << "KEYEIEI:/ 523252TTelgniSsIrettoPyhW";
}