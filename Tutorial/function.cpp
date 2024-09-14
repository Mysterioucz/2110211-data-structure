#include <iostream>

void pass_by_value(int input){ // ส่งมาแค่ค่าเท่านั้น
    input = 5;
    std::cout << "input is "<< input << std::endl;
}
void pass_by_reference(int &input){ // ส่งมาทั้งกล่องตัวแปร (ส่งมาแต่ค่าไม่ได้ต้องเป็น variable)
    input = 111;
    std::cout << "input is " << input << std::endl;
}

int main(){
    int x = 90;
    pass_by_value(x);
    std::cout << "Pass by value of X is " << x << std::endl;
    pass_by_reference(x);
    std::cout << "Pass by reference Value of X is " << x << std::endl;
    return 0;
}