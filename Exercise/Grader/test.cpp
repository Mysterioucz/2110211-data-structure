#include <iostream>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n,m;
    cin >> n >> m;
    std::ofstream outputFile("output.txt");
    map<int,int> data;
    long long fat,son;
    for (int i=0;i<n;i++){
        cin >> fat >> son;
        data[son] = fat;
    }
    vector<int> fp;
    vector<int> sp;
    long long f,s;
    for (int i=0;i<m;i++){
        cin >> f >> s;
        fp.push_back(f);
        sp.push_back(s);
    }

    for (int i=0;i<m;i++){
        f = fp[i];
        s = sp[i];
        if (f == s){
            cout << "NO" << endl;
            if (outputFile.is_open())
                {                                    // check if the file was opened successfully
                    outputFile << "NO\n"; // write data to the file
                }
        }else if (data.count(f) == 0 || data.count(s) == 0){
            cout << "NO" << endl;
            if (outputFile.is_open())
                {                                    // check if the file was opened successfully
                    outputFile << "NO\n"; // write data to the file
                }
        }else if (data.count(data[f]) == 0 || data.count(data[s]) == 0){
            cout << "NO" << endl;
            if (outputFile.is_open())
                {                                    // check if the file was opened successfully
                    outputFile << "NO\n"; // write data to the file
                }
        }else{
            if (data[data[f]] == data[data[s]]){
                cout << "YES" << endl;
                if (outputFile.is_open())
                {                                    // check if the file was opened successfully
                    outputFile << "YES\n"; // write data to the file
                }
            }else{
                cout << "NO" << endl;
                if (outputFile.is_open())
                {                                    // check if the file was opened successfully
                    outputFile << "NO\n"; // write data to the file
                }
            }
        }
    }

    return 0;
}