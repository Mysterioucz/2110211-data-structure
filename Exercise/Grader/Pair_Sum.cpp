#include <iostream>
#include <algorithm>
using namespace std;

void pair_sum(int *arr,int n,int num){
    int upper = n-1,lower = 0,total;
    while(lower < upper){
        total = arr[lower] + arr[upper];
        if( total == num){
            cout << "YES" << endl;
            return;
        }else if(total < num){
            lower++;
        }else if(total > num){
            upper--;
        }
    }
    cout << "NO" <<endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,num;
    cin >> n >> m;
    int arr[n];
    for (auto &it:arr){
        cin >> it; 
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+arr_size);
    for (int _=0; _<m; _++){
        cin >> num;
        pair_sum(arr,n,num);
    }
    return 0;
}