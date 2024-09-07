#include <iostream>
#include <map>
#include <vector>
// #include <fstream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, kj;
    string s1, s2;
    cin >> n >> m;
    map<pair<string, string>, int> ticket; // ถ้า int เป็น 1 = ยังไม่จอง
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        ticket[{s1, s2}] = 1;
    }
    vector<pair<string, string>> sold;
    bool pass = true;
    // std::ofstream outputFile("output.txt");
    for (int _ = 0; _ < m; _++)
    {
        cin >> kj;
        pass = true;
        for (int j = 0; j < kj; j++)
        {
            cin >> s1 >> s2;
            if (!pass)
            {
                continue;
            }
            if ((ticket.find({s1, s2}) == ticket.end()) || (ticket[{s1, s2}] == 0))
            { // ถ้าไม่เจอในรับบหรือขายไปแล้ว
                cout << "NO" << endl;
                // if (outputFile.is_open())
                // {                                    // check if the file was opened successfully
                //     outputFile << "NO\n"; // write data to the file
                // }
                pass = false;
            }
            else
            {
                sold.push_back({s1, s2});
            }
        }
        if (pass)
        {
            cout << "YES" << endl; // ถ้าเช็ค i<kj-1 จะมีปัญหา่
            for (auto it : sold)
            {
                ticket[it] = 0;
            }
        }
        sold.clear();
    }
    return 0;
}