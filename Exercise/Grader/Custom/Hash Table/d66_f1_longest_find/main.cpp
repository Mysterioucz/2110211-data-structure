#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFind = 1, maxInsert = 1;
vector<pair<int,int>> mBuckets; // {status,KeyT}

int find_pos(int b, int n){
    int pos = b%n, j = 0;
    while(mBuckets[pos].first != 0 && mBuckets[pos].second != b){
        j++;
        pos = (pos + 2*j - 1)%n;
    }
    return pos;
}

void hash_insert(int b, int n){
    int j = 0, idx = b%n;
    while(mBuckets[idx].first == 2){
        j++;
        idx = (idx + 2 *j - 1) % n;
    }
    mBuckets[idx] = {2,b};
}

void hash_erase(int b, int n){
    int pos = find_pos(b ,n);
    if(mBuckets[pos].first == 2 && mBuckets[pos].second == b){
        mBuckets[pos].first = 1;
        mBuckets[pos].second = -1;
    }
}

void hash_probe(){
    for(int i = 0;i < mBuckets.size();i++){
        bool insFound = false;
        if(mBuckets[i].first == 0) continue;
        int pos = i, j = 0;
        while(mBuckets[pos].first != 0){
            if(mBuckets[pos].first == 1 && !insFound){
                insFound = true;
                maxInsert = max(maxInsert,j + 1);
            }
            j++;
            pos = (pos + 2*j - 1) % mBuckets.size();
        }
        maxFind = max(maxFind , j + 1);
        if(!insFound) maxInsert = max(maxInsert, j + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,a,b;
    cin >> n >> m;
    mBuckets.resize(n,{0,0});
    while(m--){
        cin >> a >> b;
        if(a == 1) hash_insert(b,n);
        else if(a == 2) hash_erase(b,n);
    }
    hash_probe();
    cout << maxInsert << " " << maxFind << "\n";
    return 0;
}