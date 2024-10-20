#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int mFront,mSize,mCap,last,n,cor;
int check_mfront(){
    if(cor == 1){
        int front = (last - mSize + mCap)%mCap;
        return front;
    }
    return mFront < mCap;
}
int check_mSize(){
    int s = (last - mFront + mCap)%mCap;
    if(cor == 2){
        return s;
    }
    return mSize == s;
}
int check_mCap(){
    int cap = mFront + mSize - last;// TODO fix this equation
    if(cor == 3){
        return cap == 0?(last + 1):cap;
    }
    return (mCap >= mSize)&&(mCap > last);
}
int check_last(){
    int l = (mFront + mSize)%mCap;
    if(cor == 4){
        return l;
    }
    return l == last;
}
int main(){
    ofstream out("output.txt");
    ios_base::sync_with_stdio(false); cin.tie(0);
    int temp;
    cin >> n;
    while(n--){
        cin >> mFront >> mSize >> mCap >> last >> cor;
        switch(cor){
            case 0:
                if((last == mFront)&&(mSize == mCap)){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else if(check_last()&&check_mCap()&&check_mfront()&&check_mSize()){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else{
                    cout << "WRONG" << endl;
                    out << "WRONG" << endl;
                }
                break;
            case 1:
                temp = check_mfront();
                if(temp==mFront){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else{
                    cout << "WRONG " << temp << endl;
                    out << "WRONG " << temp << endl;
                }
                break;
            case 2:
                temp = check_mSize();
                if((last == mFront)&&(mSize==mCap)){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else if((mSize <= mCap)&&(temp == mSize)){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else{
                    cout << "WRONG " << temp << endl;
                    out << "WRONG " << temp << endl;
                }
                break;
            case 3:
                temp = check_mCap();
                if((last == mFront)&&(mSize==mCap)){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else if((mCap >= mSize)&&(((last >= mFront + mSize)&&(mCap >= temp))||((last < mFront + mSize)&&(mCap == temp)))){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else{
                    cout << "WRONG " << temp << endl;
                    out << "WRONG " << temp << endl;
                }
                break;
            case 4:
                temp = check_last();
                if(last == temp){
                    cout << "OK" << endl;
                    out << "OK" << endl;
                }else{
                    cout << "WRONG " << temp << endl;
                    out << "WRONG " << temp << endl;
                }
                break;
        }
    }
    return 0;
}
