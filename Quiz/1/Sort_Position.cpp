#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,num;
    cin >> n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    for(int i=0;i<n;i++){
        cin >> num;
        minHeap.push({num,i});
    }
    vector<int> res(n);
    for(int i=1; i<=n; i++){
        res[minHeap.top().second] = i;
        minHeap.pop();
    }
    for(int i=0;i<n; i++){
        cout << res[i] << " ";
    }

    return 0;
}
