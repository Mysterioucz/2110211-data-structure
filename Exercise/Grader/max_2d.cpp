#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int row,col,n,rowStart,colStart,rowEnd,colEnd;; // Global Variables

void print_vector(vector<int> vec){
    cout << "contains : ";
    for(int i = 0;i<vec.size();i++) cout << vec[i] << " ";
    cout << endl;
}

void print_2d_vector(vector<vector<int>> vec){
    cout << "Matrix :" << endl;
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec[i].size();j++){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool valid(){
    if(rowEnd < rowStart || colEnd < colStart){
            cout << "INVALID" << endl;
        }else if((0 <= rowStart && rowStart <=row) && (0 <= colStart && colStart <= col) ){
            return true;
        }else{
            cout << "OUTSIDE" << endl;
        }
    return false;
}

int main(){
    cin >> row;cin >> col;
    cin >> n;
    // cout << "Row : " << row << " Col : " << col << endl; // for debugging
    vector<vector<int>> v(row,vector<int>(col)); // initialize vector
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cin >> v[i][j];
        }
    }
    for (int _ = 0;_ < n;_++){
        cin >> rowStart;cin >> colStart;cin >> rowEnd;cin >> colEnd;
        if(valid()){
            int max = v[rowStart-1][colStart-1];
            for(int i = rowStart-1;i < min(row,rowEnd);i++){ // using min function in case that rowEnd exceed number of row of the matrix we focus only part that are in the matrix
                for(int j = colStart-1;j < min(col,colEnd);j++){
                    if(max < v[i][j])max = v[i][j];
                }
            }
            cout << max << endl;
        }
    }
    return 0;
}