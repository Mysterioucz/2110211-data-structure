#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(){
    int n;
    cin >> n; // Initialize n with a value
    vector<int> v(n);
    for(auto &it:v){
        cin >> it;
    }
    sort(v.begin(),v.end());
    int sum = accumulate(v.begin(),v.end(),0),sum2 = ((*(v.begin()) + *(v.begin()+n-1))*n/2);
    if( sum2 == sum){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}