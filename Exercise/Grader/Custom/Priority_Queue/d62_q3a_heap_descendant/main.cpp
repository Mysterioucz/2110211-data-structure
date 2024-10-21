#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n,a,count = 0;
    string ans = "";
    cin >> n >> a;
    int i,l,r,h = log2(n)/1,lvl = log2(a)/1;
    i = l = r = a;
    while((lvl <= h)&&(i < n)){
        if((l <= i)&&(i <= r)){
            count++;
            ans += to_string(i) + " ";
        }
        if(i == r){
            r = 2*r + 2;
            i = l = 2*l + 1;
        }else{
            i++;
        }
        lvl = log2(i)/1;
    }
    cout << count << endl;
    cout << ans << endl;
    return 0;
}