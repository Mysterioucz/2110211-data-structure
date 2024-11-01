#include <iostream>
#include <math.h>
// #include <fstream> // for debugging
using namespace std;

long long get_level(long long idx,long long k){
    if(k == 1){
        return idx;
    }
    long long lvl = 0;
    long long node = 1;
    while(node <= idx){
        node = node*k + 1;
        lvl++;
    }
    return lvl - 1;
}

int main(){
    // ofstream out("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n,s,a,b;
    cin >> n;
    while(n--){
        cin >> s >> a >> b;
        long long lvl_a = get_level(a,s),lvl_b = get_level(b,s);
        if(lvl_a == lvl_b){
            cout << 4 << " ";
            // out << 4 << " ";
        }else{
            long long maxNode = max(a,b);
            long long minNode = min(a,b);
            long long i = maxNode;
            if(abs(lvl_a - lvl_b) == 1){
                if((maxNode - 1)/s == minNode){
                    cout << 1 << " ";
                    // out << 1 << " ";
                    continue;
                }
            }else{
                long long lvlDiff = abs(lvl_a - lvl_b);
                while(lvlDiff--){
                    i = (i - 1)/s;
                }
                if(i == minNode){
                    cout << 2 << " ";
                    // out << 2 << " ";
                    continue;
                }
            }
            cout << 3 << " ";
            // out << 3 << " ";
        }
    }
    return 0;
}