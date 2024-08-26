#include <iostream>
// #include <set>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Set solution (slower than using 2 pointer technique)
// bool check_interval(set<pair<int,int>> &s,int num){
//     auto it = s.lower_bound({num,LLONG_MIN}); // using LLONG_MIN because the Lower bound will focus on num
//     if((it != s.end()) && (it->first <= num) && (num <= it->second)){ // if find check that num is in interval
//         return true;
//     }
//     if(it != s.begin()){ // incase that num might be in the previous interval because lower bound return a interval that not less than num it might find the closet and bigger number than num
//         it--;
//         if((it->first <= num) && (num <= it->second)){
//             return true;
//         }
//     }
//     return false;
// }

// int main(){
//     ios_base::sync_with_stdio(false); cin.tie(0);
//     int n,m;
//     int num,a,b;
//     cin >> n >> m;
//     set<pair<int,int>> s;
//     for(int i = 0; i < n; i++){
//         cin >> a >> b;
//         s.insert({a,b});
//     }
//     for(int i = 0; i < m; i++){
//         cin >> num;
//         cout << check_interval(s,num) << " ";
//     }
//     return 0;
// }

// Using bisection technique
bool check_interval(vector<pair<int, int>> &v, int num){
    int left = 0, right = v.size() - 1;
    int mid;
    while(left <= right){
        mid = (left + right)/2;
        if((v[mid].first <= num) && (num <= v[mid].second)){
            return true;
        }else if(num < v[mid].first){
            right = mid - 1;
        }else if(num > v[mid].second){
            left = mid + 1;
        }
    }
    return false;

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    int num;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    for(auto &it:v){
        cin >> it.first >> it.second;
    }
    sort(v.begin(),v.end()); 
    for(int i = 0; i < m; i++){
        cin >> num;
        cout << check_interval(v,num) << " ";
    }
    return 0;
}