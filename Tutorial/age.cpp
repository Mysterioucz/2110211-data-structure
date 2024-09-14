#include <iostream>
using namespace std;
int main(){
    int age;
    cout << "Please Enter Your age: " ; // endl มีไว้เพื่อจบบรรทัดนั้นๆ
    cin >> age;
    if ( age < 5){
        cout << "You are a kid!";
    }else if (age <100){
        cout << "You are alive!";
    }else{
        cout << "You are so close to dead!";
    }
    return 0;
}