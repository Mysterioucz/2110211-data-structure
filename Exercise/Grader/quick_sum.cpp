#include <iostream>
#include <vector>
using namespace std;

void pre_calculate(vector<vector<int>> &arr,vector<vector<int>> &p){
    p[0][0] = arr[0][0];
    for(int j = 1; j < arr[0].size(); j++){
        p[0][j] = p[0][j-1] + arr[0][j];
    }
    for(int i = 1; i < arr.size(); i++){
        p[i][0] = p[i-1][0] + arr[i][0];
        for(int j = 1; j < arr[0].size(); j++){
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + arr[i][j];
    }
    }
}

int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,m,k,r1,c1,r2,c2;
    cin >> n >> m >> k;
    vector< vector<int> > arr(n,vector<int>(m)),p(n,vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << endl;
    pre_calculate(arr,p);
    for(int _ = 0; _ < k; _++){
        cin >> r1 >> c1 >> r2 >> c2;
        if((r1 == 0)&&(c1 == 0)){
            cout << p[r2][c2] << endl;
        }else if(r1 == 0){
            cout << p[r2][c2] - p[r2][max(0,(c1-1))] << endl;
        }else if(c1 == 0){
            cout << p[r2][c2] - p[max((r1-1),0)][c2] << endl;
        }else{
            cout << p[r2][c2] - p[max((r1-1),0)][c2] - p[r2][max(0,(c1-1))] + p[max(0,(r1-1))][max(0,(c1-1))] << endl;
        }
    }
    
    

    return 0;
}
