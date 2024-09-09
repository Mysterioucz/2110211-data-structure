#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,num,global_count = 1;
    cin >> n;
    vector<int> v;
    map<int,vector<int>> freq;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    while(n--){
        cin >> num;
        v.push_back(num);
        minHeap.push(num);
    }
    vector<int> res(v);
    sort(res.begin(),res.end());
    while(!minHeap.empty()){
        auto it = minHeap.top();
        if(freq.find(it) == freq.end()){
            freq[it] = {1,global_count};
        }else{
            freq[it].push_back(global_count);
        }
        global_count++;
        minHeap.pop();
    }
    for(auto it:v){
        int index = freq[it][0];
        cout << freq[it][index] << " ";
        freq[it][0]++;
    }
    // for(auto it:v){
    //     // freq[it]++;
    //     cout << (distance(s.begin(),s.find(it)) + freq[it]) << " ";
    //     // if(freq[it] != 1){
    //     //     global_count++;
    //     // }
    // }
    return 0;
}
