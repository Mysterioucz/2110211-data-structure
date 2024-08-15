#include <iostream>
#include <vector>
using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it,int k) {
    // auto i = v.begin();
    // while(i != v.end()){ // Problem while iterating because element got delete
    //     cout << *i << " ";
    //     if((i >= it-k) && (i <= it+k)){ // it changed when erase element in vector
    //         v.erase(i);
    //     }else{
    //         i++;
    //     }
    // }
    // cout << endl;
    // Then Method that erase element in vector v directly are not work
    vector<string> res;
    for(auto i = v.begin(); i != v.end();i++){
        if(!((i >= it-k)&&(i <= it+k))) res.push_back(*i);
    }
    return res;
}
int main() {
 int n,j,k;
 cin >> n >> j >> k;
 vector<string> v(n);
 for (int i = 0;i < n;i++) {
 cin >> v[i];
 }
 cout << "Result after punch" << endl;
 vector<string> result = punch(v, v.begin() + j, k);
 for (auto &x : result) {
 cout << x << endl;
 }
}