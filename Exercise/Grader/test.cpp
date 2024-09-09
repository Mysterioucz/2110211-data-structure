#include <iostream>
#include <set>
#include <fstream>
using namespace std;

class compare{
    bool operator()(){
        return false;
    }
};

int main()
{
    set<int,compare> s={3,4,5,6};
    for(auto it:s){
        cout << it << " ";
    }
    return 0;
}