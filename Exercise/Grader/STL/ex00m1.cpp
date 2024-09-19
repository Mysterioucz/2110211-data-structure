#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, time = 0;
    cin >> n >> m;
    vector<int> T(n);
    for (auto &it : T)
    {
        cin >> it;
    }
    map<int, int> customer;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seat; // minHeap
    // int min_time = *min_element(T.begin(),T.end());
    int index = 0, i = 0;
    if (n < m)
    {
        while (i < m)
        {
            while ((!seat.empty()) && (seat.top().first == time))
            {
                index = seat.top().second;
                seat.pop();
                seat.push({time + T[index], index}); // ใส่เวลาที่เสร็จ
                customer[i] = time;                  // ใส่เวลาที่ได้รับการ serve
                if (seat.top().first == time)
                {
                    i++;
                }
            }
            if (seat.size() < n)
            {
                seat.push({time + T[index], index}); // ใส่เวลาที่เสร็จ
                customer[i] = time;                  // ใส่เวลาที่ได้รับการ serve
                index++;
            }
            if (seat.size() == n)
            {
                // time += min_time;
                time = seat.top().first;
            }
            i++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << customer[i] << endl;
    }
    return 0;
}