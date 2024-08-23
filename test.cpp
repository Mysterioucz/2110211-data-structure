#include <iostream>
#include <array>
using namespace std;

int main()
{
    map<string,int> m = {{"som",1},{"tw",2},{"ew",3}};
    auto max_elem = *(max_element(m.begin(),m.end(),[](const pair<string,int> &p1,const pair<string,int> &p2){
            return p1.second < p2.second;
    }));
    cout << (max_elem).first << (max_elem).second << endl;

    return 0;
}