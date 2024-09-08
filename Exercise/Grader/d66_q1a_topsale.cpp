#include <iostream>
#include <map>
#include <set>
#include <algorithm>
// #include <fstream>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m, prodNum, method, a, b, k;
    cin >> n >> m;
    map<int, int> prod;
    // std::ofstream outputFile("output.txt");
    multiset<pair<int, int>> set_prod;
    while (n--)
    {
        cin >> prodNum;
        prod[prodNum] = 0;
    }
    while (m--)
    {
        cin >> method;
        if (method == 1)
        {
            cin >> a >> b;
            if (prod.find(a) != prod.end())
            {
                set_prod.erase({prod[a], a}); // delete old data
                prod[a] += b;
                set_prod.insert({prod[a], a}); // insert new data
            }
        }
        else if (method == 2)
        {
            cin >> k;
            auto it = set_prod.lower_bound({k, -9999999999});
            if (it != set_prod.begin())
            {
                it--;
                cout << it->second << endl;
                // if (outputFile.is_open())
                // {                                     // check if the file was opened successfully
                //     outputFile << it->second << "\n"; // write data to the file
                // }
            }
            else
            {
                if (it->first < k)
                {
                    cout << (*set_prod.rbegin()).second << endl;

                    // if (outputFile.is_open())
                    // {                                     // check if the file was opened successfully
                    //     outputFile << it->second << "\n"; // write data to the file
                    // }
                }else{
                    cout << "NONE" << endl;
                // if (outputFile.is_open())
                // {                           // check if the file was opened successfully
                //     outputFile << "NONE\n"; // write data to the file
                // }
                }
                
            }
        }
    }
    return 0;
}