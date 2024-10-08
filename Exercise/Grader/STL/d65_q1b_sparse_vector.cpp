#include <iostream>
#include <vector>
#include <map>
// #include <fstream>
using namespace std;
void insert_into_sv(map<int, int> &v, int pos, int value)
{
    // your code here
    auto it = v.lower_bound(pos);
    vector<pair<int,int>> new_pair;
    for(auto i=it; i != v.end();i++){
        new_pair.push_back({i->first + 1,i->second});
    }
    v.erase(it,v.end());// remove old pair
    // insert new pair
    v[pos] = value;
    for(auto pair:new_pair){
        v.insert(v.end(),pair);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        insert_into_sv(v, a, b);
    }
    cout << v.size() << "\n";
    // std::ofstream outputFile("output.txt");
    for (auto &x : v)
    {
        cout << x.first << ": " << x.second << "\n";
        // outputFile << x.first << ": " << x.second << "\n";
    }
}