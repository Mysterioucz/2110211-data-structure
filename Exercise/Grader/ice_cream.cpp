#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int calIncome(int start, int P, int x, map<int, int> s, set<pair<int, int>> event)
{
    int money = start, day = 0, income = start;
    if (money >= P)
    {
        return 0;
    }
    set<pair<int, int>> e = event;
    e.insert({x, 0});
    // while(money < P){ // first sol work but slow
    //     day++;
    //     auto it = s.find(day);
    //     if(it != s.end()){
    //         income = it->second;
    //     }
    //     money += income;
    //     if((money < P)&&(day==x)){
    //         money = 0;
    //     }
    // }
    // return day;
    while (money < P)
    {
        auto it = e.upper_bound({day, 999999999});
        if (it != e.end())
        {
            if (money + income * (it->first - day - 1) + it->second > P)
            {
                if ((P - money) % income == 0)
                {
                    return day + (P - money) / income;
                }
                return day + (P - money) / income + 1;
            }
            if(it->second == 0){
                money += income * ((it->first) - day);
            }else{
                money += income * ((it->first) - day - 1) + (it->second);
                income = it->second;
            }
            
            day = it->first;
            if ((money < P) && (day == x))
            {
                money = 0;
            }
        }
        else
        {
            if ((P - money) % income == 0)
            {
                return day + (P - money) / income;
            }
            return day + (P - money) / income + 1;
        }
    }
    return day;
    // for(auto pair:s){
    //     // Check ว่าโดนหลอกก่อนวันนั้นไหม
    //     if((day< x)&&(x < pair.first)){
    //         if(money + income*(x - day -1) >= P){// ก่อนหน้านั้นเก็บได้พอดีหรือเกินไหม
    //             return day + (P-money)/income;
    //         }
    //         if(money + income*(x - day) >= P){// เก็บได้พอดีหรือเกินไหม
    //             return day + (P-money)/income;
    //         }else{
    //             money = 0;
    //             day = x;
    //         }
    //     }else{
    //         // Check  ว่าเงินครบก่อนถึงวันนั้นไหม
    //         if(money + income*(pair.first - day - 1) + pair.second > P){
    //             if((P-money)%income == 0){
    //                 return day + (P-money)/income;
    //             }
    //             return day + (P-money)/income + 1;
    //         }
    //     }
    //     money += income*(pair.first - day - 1) + pair.second;
    //     day = pair.first;
    //     income = pair.second;
    //     if(money >= P){ // เช็คว่าในวันนั้นซื้อ Parabola ได้พอดีไหม
    //         break;
    //     }
    //     if(day==x){ // Check ว่าโดนหลอกในวันนั้นไหม
    //         money = 0;
    //     }
    // }
    // return day;
}

int main()
{
    int n, m, start, a, x, P, ai;
    map<int, int> s;
    set<pair<int, int>> event;
    vector<int> res;
    cin >> n >> m >> start;
    for (int _ = 0; _ < n; _++)
    {
        cin >> a >> ai;
        s[a] = ai;
        event.insert({a, ai});
    }
    for (int _ = 0; _ < m; _++)
    {
        cin >> P >> x;
        cout << calIncome(start, P, x, s, event) << " ";
        res.push_back(calIncome(start, P, x, s, event));
    }
    cout << "-------------------------------" << endl;
    for(auto it:res){
        cout << it << endl;
    }
    return 0;
}