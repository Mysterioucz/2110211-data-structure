#include <iostream>
#include <map>
using namespace std;

int main(){
    int n,m,k,t,d,a,q;
    cin >> n >> m >> k;
    map<int,int> speed,time,temp;
    int vel = k;
    while(n--){
        cin >> t >> d;
        temp[t] = d;
    }
    for(auto i = temp.begin();i != temp.end();i++){
        vel -= i->second;
        speed[i->first] += vel;
        time[vel] = i->first;
    }
    while(m--){
        cin >> a >> q;
        if(a == 1){
            auto it = speed.upper_bound(q);
            if(it == speed.begin()){
                cout << k << endl;
                continue;
            }
            it--;
            cout << it->second << endl;
        }else if(a == 2){
            auto it = time.lower_bound(q);
            if(it == time.end()){ 
                cout << (--it)->second << endl;
                continue;
            }
            auto it1 = it;
            cout << (--it)->second - (it1)->second<< endl;
        }
    }

    return 0;
}