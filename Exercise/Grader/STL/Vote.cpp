#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n,k;
    string name;
    unordered_map<string,int> data;
    vector<pair<string,int>> v;
    cin >> n >> k;
    for(int _ = 0; _ < n; _++){
        cin >> name;
        data[name]++;
    }
    for (auto pair:data){
        v.push_back(pair);
    }
    sort(v.begin(),v.end(),[](const pair<string,int> &p1,const pair<string,int> &p2){
        return p1.second < p2.second;
    });
    if( v.size() <= k){
        cout << v[0].second;
    }else{
        cout << v[v.size() - k].second;
    }

    return 0;
}