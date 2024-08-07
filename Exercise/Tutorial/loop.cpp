#include <iostream>
using namespace std;
int main(){
    int x = 0;
    // While Loop
    while (x<= 10){
        cout << "While Loop x = "<< x << endl;
        x += 1;
    }
    // Do Loop ทำก่อนแล้วค่อยเช็คเงื่อนไข
    do {
    x++;
    cout << "Do Loop Value of X = " << x << endl; 
    } while (x<20);
    // For Loop
    for (int i =0;i<5;i++){
        cout << "x + i = " << x + i << endl; 
    }
    return 0;
}