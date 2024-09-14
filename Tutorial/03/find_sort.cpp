#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector<int> v){
    cout << "Size of V is : " << v.size() << ": ";
    for(int i = 0;i < v.size();i++){
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {9,7,8,6,5,4,2,3,1,-1};
    int x = 5;

    // find(a,b,c); หา c ตั้งแต่ a ถึงก่อน b ถ้าไม่เจอจะ return b อย่าลืม #include <algorithm> ด้วย
    if ( find(v.begin(),v.end(),x) != v.end()){ // ถ้าหาไม่เจอจะ return ขอบเขตท้ายมา
        cout << "Found" << endl;
    }else{
        cout << "Not found" << endl;
    }

    // sort(a,b) เรียงตั้งแต่ a ถึงก่อน b ต้อง #include <algorithm> ด้วย
    print_vector(v);
    sort(v.begin(),v.begin()+ 4);
    print_vector(v);

    return 0;
}