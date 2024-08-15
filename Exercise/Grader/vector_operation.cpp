#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,num;
    string method;
    vector<int> v;
    cin >> n;
    for(int _;_ < n; _++){
        cin >> method;
        if(method == "pb"){
            cin >> num;
            v.push_back(num);
        }else if(method == "sa"){
            sort(v.begin(),v.end());
        }else if(method == "sd"){
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
        }else if(method == "r"){
            reverse(v.begin(),v.end());
        }else if(method == "d"){
            cin >> num;
            v.erase(v.begin()+num);
        }
    }
    for(auto e:v){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}

