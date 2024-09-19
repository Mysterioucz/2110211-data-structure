#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cmath>
// #include <fstream>
using namespace std;

// int calIncome(int start, int P, int x, map<int, int> s)
// {
//     int money = start, day = 0, income = start;
//     if (money >= P)
//     {
//         return 0;
//     }
//     map<int, int> e(s);
//     e[x]=0;
//     while (money < P)
//     { // first sol work but slow
//         auto it = e.lower_bound(day);
//         if (it != e.end())
//         {
//             if (it->first > day)
//             {
//                 int newMoney = (money + income * (it->first - day - 1));
//                 if ( newMoney >= P)
//                 {   // เงินครบก่อนวันที่จะข้ามวันไหม
//                     // ถ้าครบก่อนวันที่จะข้ามก็ return
//                     return day + ceil((P - money + 0.00) / income);
//                 }
//                 else
//                 {                                                                                      // ถ้าไม่ครบข้ามได้
//                     money = newMoney + (it->second == 0 ? income : it->second); // ถ้า it->second == 0 แปลว่าเป็นวันที่โดนหลอกเลยต้องเพิ่มตาม income ไปอีกที
//                     day = it->first;
//                     e.erase(it);
//                 }
//             }
//         }
//         else
//         {
//             // TODO wait for implementation
//             return day + ceil((P - money + 0.00) / income);
//         }
//         auto it2 = s.find(day);
//         if (it2 != s.end())
//         {
//             income = it2->second;
//         }
//         if ((money < P) && (day == x))
//         {
//             money = 0;
//         }
//     }
//     return day;
// }
int s[100004];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // std::ofstream outputFile("output.txt");
    vector<int> res;
    
    int n, m, start, a, x, P, ai, income;
    cin >> n >> m >> start;
    for (int _ = 0; _ < n; _++)
    {
        cin >> a >> ai;
        s[a] = ai;
    }
    res.push_back(start);
    income = start;
    for (int i = 1; i < 100004; i++)
    { // Pre-Calculate
        if (s[i] > 0)
        {
            income = s[i];
        }
        res.push_back(*(res.rbegin()) + income);
    }
    for (int _ = 0; _ < m; _++)
    {
        cin >> P >> x;
        auto it = lower_bound(res.begin(), res.begin() + x, P); // ถ้าเก็บไม่ถึงก่อนวันโดนหลอกจะ return iterator ที่เป็นวันโดนหลอก(res.begin()+x) มา
        if (((it - res.begin()) == x) && (res[x] < P))
        {
            it = lower_bound(res.begin() + x, res.end(), P + res[x]);
        }
        cout << it - res.begin() << " ";
        // int temp = calIncome(start, P, x, s);
        // cout << calIncome(start, P, x, s) << " ";
        // outputFile << temp << "\n";
        // res.push_back(calIncome(start, P, x, s, event));
    }
    return 0;
}