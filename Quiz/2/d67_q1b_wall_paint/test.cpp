#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int  n,m,x,c,d;
    cin >> n >> m;
    set<pair<int,int>> wall;
    map<pair<int,int>,int> layer;
    vector<pair<int,int>> paint(m + 1);
    m *= 2;
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
            if(it == wall.begin()){
                if(e >= it->first && e <= it->second)continue;
                wall.insert(it,{s,e});
                layer[{s,e}] = 1;
                maxLayer = maxLayer < layer[{s,e}]  ? layer[{s,e}] :maxLayer;
            }else{
                if(it != wall.end()){
                    if(e >= it->first){
                        continue;
                    }
                }
                bool overlap = false;
                while(it != wall.begin()){
                    it--;
                    if((s >= it->first && s <= it->second)||(e >= it->first && e <= it->second)) overlap = true;
                    if(s > it->first && e < it->second){
                        wall.insert({s,e});
                        layer[{s,e}] = layer[*it] + 1;
                        maxLayer = maxLayer < layer[{s,e}]  ? layer[{s,e}] :maxLayer;
                        break;
                    }
                }
                if(!overlap){
                    wall.insert({s,e});
                    layer[{s,e}] = 1;
                }
            }
            
        }
    }
    cout << maxLayer << endl;

    return 0;
}