#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int a[2] = {10,20}; // Fixed array size (NonDynamic Array)
    // Dynamic Array คือการที่เรา minimize การกินทรัพยากรของ Array ด้วยการพยายามทำให้ที่ของ Array เหลือน้อยที่สุดกับจน.ข้อมูลที่มี
    // เช่น กำหนดไว้ว่า Arr1.size() = 1 พอมีจนข้อมูลเกินให้ขยายเป็น 2 เท่าจากเดิมหรืออะไรก็ว่าไป ค่อยๆขยายขนาด Array
    // Array ใน C++ ไม่สามารถนำค่ามาต่อได้
    std::cout << "a is : ";
    for(int i=0;i< std::size(a);i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    // Vector , อย่าลืม Include ด้วย, คล้าย Array แต่สามารถใส่ข้อมูลเพิ่มไปได้
    std::vector<int> b = {2,3};
    std::vector<bool> c = {true,false,true};
    
    // เพิ่มข้อมูลไปที่ตัวท้าย
    b.push_back(10);
    c.push_back(false);
    // แทรกข้อมูลตรงที่ n : (n,data)
    b.insert(b.begin(),99); // แทรกที่ตำแหน่งแรก
    b.insert(b.end(),-5); // แทรกที่ท้าย
    sort(b.begin(),b.end()); // Sort (อย่าลืม #include <algorithm>)

    // iterate ข้อมูลแต่ละตัวละปริ้น
    std::cout << "b is : ";
    for (int i =0;i < b.size(); i++){
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "c is : ";
    for(int i = 0; i < c.size(); i++){
        std::cout << c[i] << " ";
    }
    return 0;
}