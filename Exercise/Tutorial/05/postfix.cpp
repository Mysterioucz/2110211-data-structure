#include <iostream>
#include <stack>
#include <map>
using namespace std;
string infix2postfix(string &infix){
        int n= infix.length();
        map<char,int> priority = {{'+',3},{'-',3},{'*',5},{'/',5},{'^',7}};
        string postfix = "";
        stack<char> s;
        for (int i=0; i<n; i++){
            char token = infix[i];
            if((token == '+')||
               (token == '-')||
               (token == '*')||
               (token == '/')){// Check for operand
                postfix += token;
            } else{
                int p = priority[token];
                while(!s.empty() && priority[s.top()] >= p){ // ถ้า Stack ไม่ว่างและ Operator p สำคัญไม่น้อยกว่า operator บน Stack
                    postfix += s.top();
                    s.pop();
                }
                s.push(token);
            }
        }
    while(!s.empty()){postfix += s.top();s.pop();} // ดึงข้อมูลออกจาก Stack
}
    
int main(){
    // ปกติเราจะเขียนสมการคณิตแบบ Infix (เติมกลาง) แต่ปัญหาคือเราไม่รู้ว่าต้องทำ operation ไหนก่อนต้องมานั่งนึก
    // ซึ่งมีวิธีเขียนอีกแบบที่แก้ปัญหานี้ได้โดยเปลี่ยนรูปแบบการเขียนเป็นแบบ Postfix
    // เช่น Infix : a+b*c/d-2 Postfix:abc*d/+2-
    // ซึ่งเราสามารถใช้ Stack ในการคำนวณแบบ Post fix ได้
    // และเราสามารถใช้ Stack ในการแปลงจาก Infix --> Postfix

    // Conclusion Stack ใช้การดำเนินการหลัก push/pop/top
    // ถ้าจองขนาดพอ การทำงาน(push pop top)ทุกครั้งเป็น O(1) คงที่ไม่ขึ้นกับขนาด input ทำงานเร็วมาก
    return 0;
}