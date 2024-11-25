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

void hash_probe(){ // maxInsert <= maxFind เสมอ
    for(int i = 0;i < mBuckets.size();i++){ // ไล่เช็ค mBuckets แต่ละช่องโดยให้แต่ละช่องนั้นเป็น home_pos
        bool insFound = false;
        if(mBuckets[i].first == 0) continue; // ถ้าช่องว่างให้ข้าม
        int pos = i, j = 0; // home_pos is i เพราะเราไล่เช็ค mBuckets แต่ละช่อง
        while(mBuckets[pos].first != 0){ // ไล่วนหาแบบ find ช่องว่าง
            if(mBuckets[pos].first == 1 && !insFound){ // ถ้าเจอช่องแทรกได้แทรก
                insFound = true;
                maxInsert = max(maxInsert,j + 1);
            }
            j++;
            pos = (pos + 2*j - 1) % mBuckets.size();
        }
        maxFind = max(maxFind , j + 1);
        if(!insFound) maxInsert = max(maxInsert, j + 1); // กรณีที่ เราไล่ไปเรื่อยๆ แต่ไม่เจอช่องที่ Status เป็น 1 เลย
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