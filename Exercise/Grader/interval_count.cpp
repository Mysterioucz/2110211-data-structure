#include <iostream>
#include <set>
using namespace std;

void interval_check(set<unsigned int> &s,unsigned int num,unsigned int k){
    unsigned int a = num - k, b = num + k;
    auto lower = s.lower_bound(num - k);
    auto upper = s.upper_bound(num + k);
    auto dist = distance(lower,upper);
    cout << dist << " ";
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m;
    unsigned int k,num;
    set<unsigned int> s;


    cin >> n >> m >> k;

    for(int _ = 0; _ < n; _++){
        cin >> num;
        s.insert(num);
    }
    for(int _ = 0; _ < m; _++){
        cin >> num;
        interval_check(s,num,k);
    }
    return 0;
}