#include <bits/stdc++.h>
using namespace std;

int calculateScore(vector<string> key, vector<string> user){
    int score = 0;
    string sKey,sUser;
    for(int i = 0;i < key.size();i++){
        sKey = key[i];
        sUser = user[i];
        while((i< key.size() - 2)&&(key[i+1] == "_" || user[i+1] == "_")){
            i++;
            sKey += key[i];
            sUser += user[i];
        }
        score += (sKey==sUser);
    }
    return score;

    return 0;
}

int main(){
    vector<string> key = {"D","_","A","_","W","_","_","S","_"};
    vector<string> user = {"D","_","_","_","W","_"," ","S","_"};
    cout << calculateScore(key,user) << endl;
}