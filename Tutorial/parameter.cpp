#include <iostream>
using namespace std;
void test(int a){
    a = 10;
}
int main(){
    int x = 90;
    cout << "x before: " << x << endl;
    test(x);
    cout << "x after: " << x << endl;
    return 0;
}