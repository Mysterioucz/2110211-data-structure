#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    int m,n,i=0,j=0;
    cin >> m >> n;
    vector<int> v1(m),v2(n);
    set<int> res;
    for(auto &it:v1){
        cin >> it;
    }
    for(auto &it:v2){
        cin >> it;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    while(i < v1.size() && j < v2.size()){
        if (v1[i] < v2[j]){
            i++;
        }else if(v1[i] > v2[j]){
            j++;
        }else{
            res.insert(res.end(),v1[i]);
            i++;
            j++;
        }
    }
    for(auto it:res){cout << it << " ";}
    cout << endl;
    // if(m < n){
    //     sort(v1.begin(),v1.end());
    //     for(auto it:v1){
    //         if(find(v2.begin(),v2.end(),it) != v2.end()){
    //             cout << it << " ";
    //         }
    //     }
    // }else{
    //     sort(v2.begin(),v2.end());
    //     for(auto it:v2){
    //         if(find(v1.begin(),v1.end(),it) != v1.end()){
    //             cout << it << " ";
    //         }
    //     }
    // }
    // cout << endl;

    return 0;
}