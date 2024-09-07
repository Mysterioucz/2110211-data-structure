#include <iostream>
#include <set>
#include <vector>
using namespace std;

void checkPass(vector<int> &convertSource,set<string> &db,string rawPass){
    string a2z = "abcdefghijklmnopqrstuvwxyz";
    string cPass = "";
    for(int i=0 ; i<rawPass.length();i++){
        int ki = convertSource[i];
        cPass += a2z.at((a2z.find(rawPass[i]) + ki)%26);
    }
    // cout << "converted pass: " << cPass << endl;
    if(db.find(cPass) != db.end()){
        cout << "Match" << endl;
    }else{
        cout << "Unknown" << endl;
    }
    return;
}

int main(){
    int n,m,l,ki;
    string pw;
    cin >> n >> m >> l;
    vector<int> convertSource(l);
    set<string> db;
    for(auto &it:convertSource){
        cin >> it;
    }
    for(int i=0 ; i<n; i++){
        cin >> pw;
        db.insert(pw);
    }
    for(int j=0; j<m; j++){
        cin >> pw;
        checkPass(convertSource,db,pw);
    }
    return 0;
}