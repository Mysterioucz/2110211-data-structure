#include <iostream>
#include <math.h>
// #include <fstream>

using namespace std;

int main(){
    // ofstream out("output.txt");
    int n,m,a,b;
    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        if(a==b){
            cout << "a and b are the same node" << endl;
        }else{
            int l,r,h,i,j;
            i = l = r = min(a,b);
            j = max(a,b);
            int lvl_a = log2(a + 1)/1;
            int lvl_b = log2(b + 1)/1;
            h = abs(lvl_a - lvl_b); // to find level of the index we need to idx increment it by 1 before using log2 function เหมือนกับเวลาหา Height เราก็ใช้ Size
            while(h--){ // do until at the same level as max of a,b
                l = 2*l + 1; // left child
                r = 2*r + 2; // right child
            }
            if(r > n) r=n; // if right boundary are excess size of the heap set it as size of the heap
            if((l <= j)&&(j <= r)){
                if(a>b) cout << "b is an ancestor of a" << endl;
                else cout << "a is an ancestor of b" << endl;
            }else{
                cout << "a and b are not related" << endl;
            }
        }
    }
    return 0;
}