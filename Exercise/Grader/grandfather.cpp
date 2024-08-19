#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    long long f,s,a,b,f_a,f_b,g_a,g_b;
    map<long long,long long> data;
    cin >> n >> m;
    for (int _ = 0; _ < n; _++){
        cin >> f >> s;
        if(data.find(s) == data.end()){
            data[s] = f;
        }
    }
    for (int _ = 0; _ < m; _++){
        cin >> a >> b;
        if((data.find(a) != data.end())&&(data.find(b) != data.end()) && (a != b)){
            f_a = data[a];
            f_b = data[b];
            if((data.find(f_a) != data.end())&&(data.find(f_b) != data.end())){
                g_a = data[f_a];
                g_b = data[f_b];
                if(g_a == g_b){
                    cout << "YES" <<endl;
                    continue;
                }
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}