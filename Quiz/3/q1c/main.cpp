#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    set<pair<int,int>> s;
    int n,m,temp;
    long long total = 0;
    cin >> n >> m;
    for(int i = 1; i <= n;i++){
        cin >> temp;
        s.insert({temp,i});
        total += temp;
    }
    while(m--){
        cin >> temp;
        if(temp > total){
            cout << -1 << endl;
        }else{
            auto it = s.lower_bound({temp,n});
            if(it != s.end()){
                cout << it->second << " " << temp;
                total -= temp;
                int a = (it->first) - temp,b = it->second;
                s.erase(it);
                if(a > 0){
                    s.insert({a,b});
                }
            }else{
                vector<pair<int,int>> res;
                while((temp > 0)&&(!s.empty())){
                    if(it != s.end()){
                        res.push_back({it->second,temp});
                        total -= temp;
                    }else{
                        it--;
                        res.push_back({it->second,it->first});
                        total -= it->first;
                    }
                    int a = it->first - temp,b = it->second;
                    temp -= it->first;
                    s.erase(it);
                    if(a > 0){
                        s.insert({a,b});
                    }        
                    it = s.lower_bound({temp,n});
                }
                sort(res.begin(),res.end());
                for(pair<int,int> p:res){
                    cout << p.first << " " << p.second << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}