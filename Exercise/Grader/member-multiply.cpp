#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void member_multiply(vector<int> &v,
                     vector<pair<vector<int>::iterator, int>> &multiply)
{
    // int count = 0;
    vector <int> res = v;
    sort(multiply.begin(),multiply.end(),[](const pair<vector<int>::iterator, int> &p1, const pair<vector<int>::iterator, int> &p2){
        return p1.first < p2.first;
    });
    // write your code here
    // Sol1: Can't use insert to v directly because iterator will change
    // for(auto pair:multiply){
    //     v.insert(pair.first + count,pair.second,*(pair.first+count));
    //     count += pair.second;
    // }
    //
    // Sol2: The arithmatic of (res.begin() + (pair.first - v.begin()) + count) may wrong due to something?
    // for (size_t i = 0; i < multiply.size(); ++i)
    // {
    //     pair<vector<int>::iterator, int> pair = multiply[i];
    //     res.insert((res.begin() + (pair.first - v.begin()) + count), pair.second, *(pair.first));
    //     count += pair.second;
    // }
    int m_index = 0, v_index = 0;
    while( m_index < multiply.size() && v_index < v.size()){
        if(m_index < multiply.size() && (multiply[m_index].first - v.begin() == v_index)){
            res.insert(res.end(), multiply[m_index].second, v[v_index]);
            m_index++;
        }
        if(v_index < v.size()){
            res.push_back(v[v_index]);
            v_index++;
        }
    }
    v = res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<pair<vector<int>::iterator, int>> multiply(m);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        multiply[i].first = v.begin() + a;
        multiply[i].second = b;
    }
    member_multiply(v, multiply);
    cout << "======= result ========" << endl;
    cout << v.size() << endl;
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}