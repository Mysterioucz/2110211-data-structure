#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>

using namespace std;

int main(){
    int  n,m,x,c,d;
    cin >> n >> m;
    m *= 2;
    set<pair<int,int>> wall;
    map<pair<int,int>,int> layer;
    vector<pair<int,int>> paint(m/2 + 1);
    while(m--){
        cin >> x >> c >> d;
        if(d){
            paint[c].second = x;
        }else{
            paint[c].first = x;
        }
    }
    int maxLayer = 0;
    for(int i = 1;i < paint.size();i++){
        int s = paint[i].first, e = paint[i].second;
        if(wall.empty()){
            wall.insert({s,e});
            layer[{s,e}] = 1;
            maxLayer = 1;
        }else{
            auto it = wall.lower_bound({s,e});
            if((it != wall.end())&&(e < it->first)){
                if(it != wall.begin())it--;
                else{
                    wall.insert({s,e});
                    layer[{s,e}] = 1;
                    maxLayer = maxLayer < layer[{s,e}]  ? layer[{s,e}] :maxLayer;
                    continue;
                }
                if((s > it->second)){ // between existing interval
                    wall.insert({s,e});
                    layer[{s,e}] = 1;
                    maxLayer = maxLayer < layer[{s,e}]  ? layer[{s,e}] :maxLayer;
                }else if((s > it->first)&&(e < it->second)){ // inside interval
                    wall.insert({s,e});
                    layer[{s,e}] = layer[*it] + 1;
                    maxLayer = maxLayer < layer[{s,e}]  ? layer[{s,e}] :maxLayer;
                }
            }else{
                it--;
                if((s > it->first)&&(e < it->second)){
                    wall.insert({s,e});
                    layer[{s,e}] = layer[*it] + 1;
                    maxLayer = maxLayer < layer[{s,e}]  ? layer[{s,e}] :maxLayer;
                }else if(s > it->second ){
                    wall.insert({s,e});
                    layer[{s,e}] = 1;
                    maxLayer = maxLayer < layer[{s,e}]  ? layer[{s,e}] :maxLayer;
                }
            }
            
        }
    }
    cout << maxLayer << endl;

    return 0;
}