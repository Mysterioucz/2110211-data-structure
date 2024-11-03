#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k, t, d, a, q;
    cin >> n >> m >> k;
    map<int, int> speed, time;
    vector<pair<int, int>> temp(n);
    int vel = k;

    // Input phase: Store events in a vector for sorting
    for(int i = 0; i < n; i++) {
        cin >> t >> d;
        temp[i] = {t, d};
    }
    
    // Sort events by time to maintain order
    sort(temp.begin(), temp.end());

    // Process each time event
    for(auto& event : temp) {
        t = event.first;
        d = event.second;
        vel -= d;
        if (vel < 0) vel = 0;
        speed[t] = vel;
        if (time.find(vel) == time.end()) {
            time[vel] = t;
        }
    }

    // Query phase
    vector<int> timestamps;
    for (const auto& s : speed) timestamps.push_back(s.first);
    sort(timestamps.begin(), timestamps.end());
    while (m--) {
        cin >> a >> q;
        if (a == 1) {
            auto it = upper_bound(timestamps.begin(), timestamps.end(), q);
            if (it == timestamps.begin()) {
                cout << k << endl;
            } else {
                it--;
                cout << speed[*it] << endl;
            }
        } else if (a == 2) {
            auto it = time.lower_bound(q);
            if (it == time.begin()) {
                cout << (it->second) + 1 << endl;
            } else if (it == time.end() && q > k) {
                cout << 0 << endl;
            } else {
                cout << (--it)->second << endl;
            }
        }
    }

    return 0;
}
