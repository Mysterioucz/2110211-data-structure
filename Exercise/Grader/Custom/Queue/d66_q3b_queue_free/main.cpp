#include <iostream>
#include <math.h>

using namespace std;

int main(){
    size_t mSize = 0,mCap = 1;
    int n,a,k;
    cin >> n;
    while(n--){
        cin >> a >> k;
        if(a == 0){
            if(mSize + k > mCap){
                mCap = pow(2,(ceil(log2(mSize + k))));
            }
            mSize += k;
        }else if(a == 1){
            mSize -= k;
        }
    }
    cout << (mCap - mSize) << endl;

    return 0;
}