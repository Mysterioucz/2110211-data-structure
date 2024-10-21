#include <iostream>
#include <vector>

using namespace std;

void heap_check(const vector<int> &v,int k){
    for(int j = 0;j < (k*v.size() + 1);j++){ // check the node that have left child
        int l = k*j + 1; // left most child
        while(((l-1)/k == j)&&(l < v.size())){
            if(v[l] > v[j]){
                cout << "false" << endl;
                return;
            }
            l++;
        }
    }
    cout << "true" << endl;
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int m,n,k;
    cin >> m;
    while(m--){
        cin >> n >> k;
        vector<int> v(n);
        for(auto &e:v){
            cin >> e;
        }
        heap_check(v,k);
    }
    return 0;
}