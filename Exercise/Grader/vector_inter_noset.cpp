#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void intersection(vector<int> v_less,vector<int> v){
    sort(v_less.begin(),v_less.end());
    vector<int> res;
    for(auto e:v_less){
        if((find(v.begin(),v.end(),e) != v.end())){
            if(((find(res.begin(),res.end(),e) == res.end()))||(res.empty())){
                cout << e << " ";
                res.push_back(e);
            }
        }
    }
    cout << endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> v1(n),v2(m);
    for (auto &it1:v1){
        cin >> it1;
    }
    for (auto &it2:v2){
        cin >> it2;
    }
    if(n < m){
        intersection(v1,v2);
    }else{
        intersection(v2,v1);
    }
    return 0;
}

