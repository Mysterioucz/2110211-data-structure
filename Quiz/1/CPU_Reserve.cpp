#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,a,b;
    cin >> n;
    vector<int> res;
    set<pair<int,int>> occupied;
    for(int i=1; i < n+1; i++){
        cin >> a >> b;
        if(occupied.empty()){
            occupied.insert({a,b});
            res.push_back(i);
        }else{
            auto it = occupied.lower_bound({a,b});
            if(it == occupied.end()){
                it--;
                int bi = it->second;
                if(a>bi){
                    res.push_back(i);
                    occupied.insert(occupied.end(),{a,b});
                }
            }else if(it == occupied.begin()){
                int ai = it->first;
                if(b<ai){
                    res.push_back(i);
                    occupied.insert(occupied.begin(),{a,b});
                }
            }else{
                int ai = it-> first,bi = (--it)->second;
                if((a>bi)&&(b<ai)){
                    res.push_back(i);
                    occupied.insert(it,{a,b});
                }
            }
            
        }
    }
    for(auto e:res){
        cout << e << " ";
    }
    return 0;
}