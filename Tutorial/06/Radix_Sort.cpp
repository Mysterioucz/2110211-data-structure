#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define base 10

int getDigit(int v, int k){
    int i;
    for(i = 0; i<k; i++){
        v /= base;
    }
    return v % base;
}

void radixSort(vector<int> &data,int d){
    queue<int> q[base];
    for(int k=0; k<d; k++){
        for(auto &x:data){
            q[getDigit(x,k)].push(x);
        }
        for(int i=0,j=0; i<base;i++){
            while(!q[i].empty()){
                data[j++] = q[i].front();
                q[i].pop();
            }
        }
    }
}

int main(){
    // Queue Application: Fast sorting with no comparison

    return 0;
}