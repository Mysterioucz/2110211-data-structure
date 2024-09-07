#include <iostream>
#include <unordered_map>
#include <set>
#include <fstream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, kj;
    string s1, s2;
    cin >> n >> m;
    unordered_map<string, multiset<string>> ticket; // ถ้า int เป็น 0 = ยังไม่จอง
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        ticket[s1].insert(s2);
    }
    multiset<pair<string, string>> sold;
    multiset<pair<string, string>> prev_sold;
    bool pass = true;
    // std::ofstream outputFile("output.txt");
    for (int _ = 0; _ < m; _++)
    {
        cin >> kj;
        pass = true;
        for (int j = 0; j < kj; j++)
        {
            cin >> s1 >> s2;
            if (pass)
            {
                if ((ticket[s1].find(s2) == ticket[s1].end()) || (prev_sold.find({s1, s2}) != prev_sold.end()))
                { // ถ้าไม่เจอในรับบหรือขายไปแล้ว
                    cout << "NO" << endl;
                    // if (outputFile.is_open())
                    // {                                    // check if the file was opened successfully
                    //     outputFile << "NO\n"; // write data to the file
                    // }
                    sold.clear(); // reset sold ticket
                    pass = false;
                }
                else
                {
                    sold.insert({s1, s2});
                }
            }
        }
        if (pass)
        {
            cout << "YES" << endl;
            // if (outputFile.is_open())
            // {                                    // check if the file was opened successfully
            //     outputFile << "YES\n"; // write data to the file
            // }
            prev_sold.insert(sold.begin(), sold.end()); // update sold ticket
        }
    }
    return 0;
}
