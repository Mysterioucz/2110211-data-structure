#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int,5> a = {0};
    int* arr = new int[5];
    for(auto it = a.begin();it != a.end(); it++){
        cout << *it;
    }
    cout << endl;
    for (int i = 0; i < 5; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << arr.size() << endl;
    // freeing-up memory space by deleting arr 
    delete[] arr; 


    return 0;
}