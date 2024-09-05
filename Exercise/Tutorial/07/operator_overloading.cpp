#include <iostream>
#include <string>
using namespace std;

string operator*(string &lhs, const int &rhs){ // & : pass by reference (ต้องเป็น Object เท่านั้น)
    string result = "";
    for (int i=0 ; i < rhs; i++){
        result = result + lhs;
    } // lhs : Left Hand Side, rhs : Right Hand Side
    return result;
}

int main(){
    string a = "AbC ";
    cout << (a*9) << endl; // ปกติคุณ int & string ไม่ได้แต่เรา Custom ให้ทำได้
    return 0;
}