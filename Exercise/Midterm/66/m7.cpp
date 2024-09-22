#include <bits/stdc++.h>
using namespace std;

void attack(vector<char> &power, string input){
    string pow,key = input;
    for(auto str:power){pow += str;}
    auto pos = pow.find(key);
    int i = 0;
    while((pos == -1)&&(i < input.size() - 1)){
        key = input[i] + input[i+1];
        pos = pow.find(key);
        i++;
    }
    if(pos == -1){return;}
    i += 2;
    while(i < input.size()){
        string nKey = key;
        nKey += input[i];
        auto nPos = input.find(nKey);
        if(nPos != -1){
            key = nKey;
        }else{
            break;
        }
        i++;
    }
    const string oPow = pow;
    auto uPos = oPow.find(key);
    while((pos != -1)&&(uPos != -1)){
        pow.erase(pos,key.size());
        pos = pow.find(key);
        uPos = oPow.find(key,uPos + 1);
    }
    power.clear();
    for(auto ch:pow){power.push_back(ch);}
}

int main(){
    vector<char> power = {'I','a','m','S','a','m'};
    // vector<char> power = {'a','a','a','M','M','M'};
    string input;
    cin >> input;
    attack(power,input);
    for(auto ch:power){
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}