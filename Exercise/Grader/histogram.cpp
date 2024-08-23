#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    string name;
    map<string,int> m;
    cin >> n;
    for(int _ = 0; _ < n; _++){
        cin >> name;
        m[name]++;
    }
    for(auto pair:m){
        if(pair.second > 1){
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}