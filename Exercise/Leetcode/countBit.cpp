#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &v){
    cout << "Vector contains : ";
    for (auto it:v){
        cout << it << " ";
    }
    cout << endl;
}

vector<int> countBits(int n) {
    vector<int> res(n+1);
    int m;
    for(int i=0 ; i <= n ;i++){
        m=i;
        while( m > 0){
            res[i] += m%2;
            m /= 2;
        }
    }
    return res;
}

int main(){
    vector<int> bits = countBits(5);
    print_vector(bits);
    return 0;
}