#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v(5);
    cout << v.end() - v.begin();
    return 0;
}