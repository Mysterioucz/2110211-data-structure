#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main(){
    //TODO need to implement to run faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    ofstream out("output.txt");
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
        if(vel<0) vel = 0;
        speed[i->first] += vel;
        if(time.find(vel) == time.end()){
            time[vel] = i->first;
        }
    }
    while(m--){
        cin >> a >> q;
        if(a == 1){
            auto it = speed.upper_bound(q);
            if(it == speed.begin()){
                cout << k << endl;
                out << k << endl;
                continue;
            }
            it--;
            cout << it->second << endl;
            out << it->second << endl;
        }else if(a == 2){
            auto it = time.lower_bound(q);
            if(it == time.begin()){ 
                cout << (it)->second + 1 << endl;
                out << (it)->second + 1 << endl;
                continue;
            }else if(it == time.end()){
                if(q>k){
                    cout << 0 << endl;
                    out << 0 << endl;
                    continue;
                }
            }
            cout << (--it)->second<< endl;
            out << (it)->second<< endl;                
        }
    }

    return 0;
}