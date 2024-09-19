#include <iostream>
#include <set>
using namespace std;

void check_hiatus(set<pair<int,int>> &s, pair<int,int> &time){
    if(s.find(time) != s.end()){
        cout << "0 0 ";
        // cout << time.first << " " << time.second << " ";
        return;
    }else if(time < *(s.begin())){
        cout << "-1 -1 ";
        return;
    }else{
        auto recent = *(--s.lower_bound(time));
        cout << recent.first << " " << recent.second << " ";
        return;
    }
}

// Sol: Using bisection
int main(){
     ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    pair<int,int> time;
    cin >> n >> m;
    set<pair<int,int>> s;
    for (int i = 0; i < n; i++){
        cin >> time.first >> time.second;
        s.insert(time);
    }
    for (int i = 0; i < m; i++){
        cin >> time.first >> time.second;
        check_hiatus(s,time);
    }

    return 0;
}