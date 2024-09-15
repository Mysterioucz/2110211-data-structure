#include <iostream>
using namespace std;

int main(){
    int n,cap = 1;
    cin >> n;
    while (cap < n){
        cap *= 2;
    }
    cout << cap-n << endl;
    return 0;
}