#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
    // map<string,int> m = {{"som",1},{"tw",2},{"ew",3}};
    // auto max_elem = *(max_element(m.begin(),m.end(),[](const pair<string,int> &p1,const pair<string,int> &p2){
    //         return p1.second < p2.second;
    // }));
    // cout << (max_elem).first << (max_elem).second << endl;
    map<string,set<string>> m;
    m["a"].insert("ko");
    cout << *m["a"].begin() << endl;


    return 0;
}