#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// void prune(priority_queue<int, vector<int>, greater<int>> &pq,unordered_map<int,int> freq){
//         while (!pq.empty() && (freq.find(pq.top()) == freq.end())) {
//             pq.pop();
//         }
// }
// void prune (priority_queue<int> &pq,unordered_map<int,int> freq) {
//         while (!pq.empty() && (freq.find(pq.top()) == freq.end())) {
//             pq.pop();
//         }
// }

void findMedian(vector<int> &v,int w,int n){

    multiset<int> maxHeap;
    multiset<int> minHeap;
    unordered_map<int,int> freq;

    auto heapBalance = [&](){
        if(minHeap.size() >= maxHeap.size()+1){ // ไม่มีทางเท่ากัน(เพราะเราจะ Remove ออกจนเหลือแต่จน.คี่อยู่แล้ว)
            auto it = minHeap.begin();
            maxHeap.insert(*it);
            minHeap.erase(it);
        }else if((minHeap.size() + 1 < maxHeap.size())){
            auto it = --maxHeap.end();
            minHeap.insert(*it);
            maxHeap.erase(it);
        }
    };
    auto add = [&](int num){
        freq[num]++;
        if(maxHeap.empty() || num < *maxHeap.rbegin()){
            maxHeap.insert(num);
        }else{
            minHeap.insert(num);
        }
        heapBalance();// For balancing Heap
    };

    auto remove = [&](int num){
        freq[num]--;
        if(num > *maxHeap.rbegin()){// แปลว่า Median จะขยับขึ้นเอาก้อนบนออก
            auto it = minHeap.find(num);
            minHeap.erase(it);
        }else{// แปลว่า Median จะขยับลงเอาก้อนล่างออก
            auto it = maxHeap.find(num);
            maxHeap.erase(it);
        }
        // heapBalance();
    };
    

    auto getMedian = [&]() -> int{
        return *maxHeap.rbegin();
    };

    for(int i=0; i<v.size(); i++){
        if(i<w){
            add(v[i]);
        }else{
            add(v[i]);
            // heapBalance();
            cout << getMedian() << " ";
            remove(v[i-w]);
        }
        if((i+1 == v.size())&&(i<w)){
            cout << getMedian() << " ";
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,w;
    cin >> n >> w;
    vector<int> v(n);
    for(auto &it:v){
        cin >> it;
    }
    findMedian(v,w,n);
}