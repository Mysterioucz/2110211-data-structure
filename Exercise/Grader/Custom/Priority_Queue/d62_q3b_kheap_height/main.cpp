#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long n,k;
    cin >> n >> k;
    if(k == 1){
        cout << n-1 << endl;
    }else{
        
        cout << ceil((log((k - 1)*n + 1))/1/(log(k)/1) - 1) << endl;
    }
    return 0;
}