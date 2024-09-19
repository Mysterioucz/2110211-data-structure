#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// class compare{
//     public:
//     bool operator()(const pair<int,int> &a,const pair<int,int> &b){
//         if(a.second == b.second){
//             return a.first < b.first;
//         }
//         return a.second < b.second;
//     }
// };

void initUser(map<int, vector<int>> &users,int m){
    for(int i=1 ;i<=m;i++){
        users[i] = {};
    }
}

int main()
{
    int n, m, a, ki, u, i, v;
    string method;
    cin >> n >> m >> a;
    map<int, int> items;
    map<int, vector<int>> users;
    map<int, map<int, int>> auct;
    for (int i = 1; i <= n; i++)
    {
        cin >> ki;
        items[i] = min(10, ki);
    }
    for (int _ = 0; _ < a; _++)
    {
        cin >> method;
        if (method == "B")
        {                       // Bid
            cin >> u >> i >> v; // user item value
            auct[i][u] = v;     // new bid will always overwrite the old one
            // if(auct[i].size() > items[i]){// if amount of bid more than item remove the lowest bid
            //     auct[i].erase(auct[i].begin());
            // }
        }
        else if (method == "W")
        { // Withdraw
            cin >> u >> i;
            if (auct[i].find(u) != auct[i].end())
            {// ถ้าเคยบิดให้เอาออก
                auct[i].erase(u);
            }//ถ้าไม่เคยไม่ต้องทำไร
        }
    }

    initUser(users,m);

    for (int i = 1; i <= n; i++)
    {
        if(!auct[i].empty()){// ถ้าของประเภทนี้เกิดการประมูล
            if(auct[i].size() > items[i]){//ถ้าจำนวนคนบิดมากกว่าจำนวนของ
                vector<pair<int,int>> sold;// price,user
                for(auto pair:auct[i]){
                    sold.push_back({pair.second,pair.first});// collect data in {price,user}
                }
                sort(sold.begin(),sold.end()); // sort the price and user label
                for(auto it=sold.rbegin(); it < sold.rbegin() + items[i]; it++){
                    users[it->second].push_back(i);
                }
            }else{
                for(auto pair:auct[i]){
                    users[pair.first].push_back(i);
                }
            }
            

        }
    }
    for(auto pair:users){
        if(!pair.second.empty()){
            for(auto item:pair.second){
                cout << item << " ";
            }
        }else{
            cout << "NONE";
        }
        cout << endl;
    }

    return 0;
}