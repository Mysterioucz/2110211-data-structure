#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void interval_check(vector<long long> &v,long long num,long long k){
    long long a = num - k, b = num + k;
    auto lower = lower_bound(v.begin(),v.end(),a);
    auto upper = upper_bound(v.begin(),v.end(),b);
    auto dist = upper - lower; // ถ้าใช้ Set และใช้ std::distance() จะช้ากว่ามาก
    cout << dist << " ";
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m;
    long long k,num;
    vector<long long> v;

    cin >> n >> m >> k;
    for(int _ = 0; _ < n; _++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int _ = 0; _ < m; _++){
        cin >> num;
        interval_check(v,num,k);
    }
    return 0;
}