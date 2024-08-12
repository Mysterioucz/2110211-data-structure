#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

void print_time(int num){ // For printing in Clock form (09 50)
    if(num == 0){
        cout << "00";
    }else if(num < 10){
        cout << "0" << num;
    }else{
        cout << num;
    }
}
int main(){
    int hour,min,total_min,new_hour,new_min;
    cin >> hour >> min;
    cin >> total_min;
    new_min = (min + total_min) - (((total_min + min)/60)*60);
    new_hour = hour + ((total_min+min)/60);
    if(new_hour > 23){
        new_hour -= (new_hour/24)*24; // In case that new_hour is exceed 23
    }
    print_time(new_hour);cout << " ";print_time(new_min);
    return 0;
}