#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<pair<int, int>> rearrange(m+1);
    for(int i = 0 ; i < 2 * m; i++){
        int pos, count, d;
        cin >> pos >> count >> d;
        if(d == 0){
            rearrange[count].first = pos;
        }
        else if(d == 1){
            rearrange[count].second = pos;
        }
    }
    set <int> s;
    s.insert(0);
    vector<pair<int, int>> layers(n+1);
    layers[0] = {0, n+1};
    int ans = 0;
    for(int i = 1; i <= m; i++){
        auto it = s.upper_bound(rearrange[i].first);
        it--;
        if(layers[*it].second <= rearrange[i].second || *it == rearrange[i].first) continue;
        layers[rearrange[i].first] = {layers[*it].first + 1, rearrange[i].second};
        ans = max(ans, layers[rearrange[i].first].first);
        layers[rearrange[i].second] = layers[(*it)];
        layers[*it].second = rearrange[i].first;
        s.insert(rearrange[i].first);
        s.insert(rearrange[i].second);
    }

    cout << ans;
}
