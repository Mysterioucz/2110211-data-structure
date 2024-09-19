#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> data(m);
    vector<pair<int,int>> newHero(n);
    unordered_map<int,int> freq;
    for(int i=0 ;i<m;i++){
        data[i] = 1;
        freq[1]++;
    }
    for(auto &it:newHero){
        cin >> it.second;
    }
    priority_queue<int, vector<int>, greater<int>> minHeap(data.begin(), data.end());
    for(auto &it:newHero){
        cin >> it.first;
        if(data[it.first] < it.second){
            freq[data[it.first]]--;
            if(freq[data[it.first]] == 0){
                freq.erase(data[it.first]);
            }
            data[it.first] = it.second;
            freq[it.second]++;
        }
        minHeap.push(it.second);
        while (!minHeap.empty() && (freq.find(minHeap.top()) == freq.end())) {
            minHeap.pop();
        }
        cout << minHeap.top() << " ";
    }
    cout << endl;
    return 0;
}