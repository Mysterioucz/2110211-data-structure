#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v){
    cout << "Size of V is : " << v.size() << ": ";
    for(int i = 0;i < v.size();i++){
        cout << v[i] << ", ";
    }
    cout << endl;
}
int main(){
    vector<int> y;
    cout << "Size of y when got initiated is " << y.size() << endl;

    // Vector Access & Overflow
    vector<float> v1(2);
    vector<float> v2(2);
    cout << "v1 size is " << v1.size() << "\nv2 size is " << v2.size() << endl;

    //Overflow test
    cout << "Read Test :" << endl;
    for(int i = 0 ;i < 7 ;i++){ // Read test
        cout << "v1[" << i << "] is " << v1[i] << endl;
    }
    // Write test
    cout << "Write Test :" << endl; 
    for(int i = 0 ;i < 7 ;i++){ // Read test
        v2[i] = i;
        cout << "v2[" << i << "] is " << v2[i] << endl;
    }
    // การ Overflow อ่าน/เขียนข้อมูลที่ไม่ได้จองอาจเกิด Buffer Overflow (ข้อมู,ที่เขียนใน memory อาจทับกันเช่นเขียน v1 เกินขนาดละไปทับ v2)
    // Modifying Vector 
    vector<int> v3(2);
    cout << "Modifying Vector\nv3 : ";
    for(int j = 0;j < 5;j++){
        v3[j] = j;
        cout << v3[j] << " ";
    }
    cout << endl;
    v3.resize(5);
    print_vector(v3);

    // 2D Vector
    vector<vector<int>> vector_2d(5,vector<int>(5));
    return 0;
}