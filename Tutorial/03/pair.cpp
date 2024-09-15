#include <iostream>

int main(){
    std::pair<bool,int> x;
    std::cout << "First value of x is " <<x.first << "\nSecond value of x is " << x.second << std::endl;
    // ไม่สามารถ cout pair ออกไปตรงๆได้

    return 0;
}