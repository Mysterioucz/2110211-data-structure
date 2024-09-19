#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

void print(map<string,pair<double,int>> &m){
    for(auto key:m){
            auto pair = key.second;
            cout << key.first << " " << (pair.first + 0.0)/pair.second << endl;
        }
}

int main(){
    cout << std::fixed << std::setprecision(2); // ให้พิมทศนิยม 2 ตน
    int n,point;
    string subject,teacher;
    map<string,pair<double,int>> t,s; // "ชื่อวิชา/ผู้สอน","คะแนน","จำนวน"
    cin >> n;
    for(int _ = 0; _ < n; _++){
        cin >> subject >> teacher >> point;
        s[subject].first += point;
        s[subject].second++;
        t[teacher].first += point;
        t[teacher].second++;
    }
    print(s);
    print(t);
    
    return 0;
}