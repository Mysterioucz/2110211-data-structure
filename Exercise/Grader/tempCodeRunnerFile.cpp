#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, kj;
    string s1, s2;
    cin >> n >> m;
    unordered_map<string, set<string>> ticket;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (ticket[s1].empty())
        {
            ticket[s1] = {};
        }
        ticket[s1].insert(s2);
    }
    unordered_map<string, set<string>> sold = ticket;
    bool pass = true;
    for (int _ = 0; _ < m; _++)
    {
        cin >> kj;
        for (int i = 0; i < kj; i++)
        {
            cin >> s1 >> s2;
            if (pass)
            {
                if (ticket[s1].find(s2) == ticket[s1].end())
                {
                    cout << "NO" << endl;
                    sold[s1] = ticket[s1]; // reset sold ticket
                    pass = false;
                }
                else if (i == kj - 1)
                { // เจอตัวเครื่องบินและเป็นตั๋วที่จะซื้ออันท้าย
                    cout << "YES" << endl;
                    ticket[s1] = sold[s1]; // update avaiavle ticket
                }
                else
                {
                    sold[s1].erase(s2);
                }
            }
        }
        pass = true;
    }
    return 0;
}