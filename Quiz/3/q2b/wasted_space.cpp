#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long int n,q,mCap = 1,mSize = 0;
    string p;
    cin >> n;
    while(n--){
        cin >> p >> q;
        if(p == "p"){
            while(mSize + q > mCap){
                // mCap = pow(2,ceil(log(mSize + q)/log(2)));
                mCap <<= 1;// same as mCap *= 2;
            }
            mSize += q;
        }else if(p == "o"){
            mSize -= q;
            if(mSize < 0) mSize = 0;
        }else if(p == "r"){
            if(q > mCap)mCap = q;
            mSize = q;
        }
    }
    cout << mCap - mSize << endl;
    return 0;
}