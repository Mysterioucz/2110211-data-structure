#include <iostream>
#include <algorithm>
using namespace std;

void pair_sum_2pointer(int arr[], int n, int num) {
    //using 2 Pointer(Lower & Upper)
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
void pair_sum_find(int arr[], int n, int num){
    int search_key, *begin=arr, *end = arr+n;
    for(int i = 0; i < n; i++){
        search_key = num - arr[i];
        if(find(begin+i+1,end,search_key) != end){ // using begin+i+1 because it must not use itself as candidate
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,num;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+arr_size);
    for (int _=0; _<m; _++){
        cin >> num;
        pair_sum_2pointer(arr, n, num);
        // pair_sum_find(arr, n, num); // This one time out
    }
    return 0;
}