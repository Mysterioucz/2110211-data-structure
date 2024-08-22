#include <iostream>
#include <unordered_map>
#include <algorithm> // std::max_element, std::min_element
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    string key;
    unordered_map<string,int> m;
    cin >> n;
    for (int _ = 0; _ < n; _++){
        cin >> key;
        m[key]++; // It create and set value to 0 then +1
        // if(m.find(key) != m.end()){
        //     m[key]++;
        // }else{
        //     m[key] = 1;
        // }
    }
    auto max_val = max_element(m.begin(),m.end(),[](const pair<string,int> &p1,const pair<string,int> &p2) {
        if(p1.second == p2.second){
            return (p1.first < p2.first);
        }
        return (p1.second < p2.second);
    });// using Lambda Function [capture clause](parameter){return something (in this case return boolean)}
    cout << (*max_val).first << " " << (*max_val).second << endl;
    return 0;
}