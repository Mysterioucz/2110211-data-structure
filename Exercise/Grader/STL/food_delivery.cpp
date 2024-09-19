#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Compare
{
    bool operator()(const vector<int> &p1, const vector<int> &p2)
    {
        if (p1[1] != p2[1])
        {
            if (p1[0] == p2[0])
            {
                return p1[1] > p2[1]; // if price are the same compare by shop
            }
            return p1[0] > p2[0]; // Prioritize cheaper price
        }
        return p1[2] > p2[2]; // If shops are the same, prioritize by timestamp
    }
};

void update_target(vector<pair<int, int>> &target, int total, int c)
{
    for (auto &pair : target)
    {
        if ((pair.first <= total) && (pair.second == -1))
        {
            pair.second = c;
        }
    }
}

void cook(vector<pair<int, int>> &target,
          priority_queue<vector<int>, vector<vector<int>>, Compare> &order,
          int &total, int &c)
{
    c++;
    auto menu = order.top();
    total += menu[0];
    order.pop();
    update_target(target, total, c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, temp, a, b;
    int total = 0;
    int c = 0;
    cin >> n >> m;
    vector<pair<int, int>> target(m, {0, -1});
    priority_queue<vector<int>, vector<vector<int>>, Compare> order;

    for (int i = 0; i < m; i++)
    {
        cin >> temp;
        target[i].first = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 1)
        {
            cin >> a >> b;
            order.push({b, a, i});
        }
        else if (temp == 2)
        {
            cook(target, order, total, c);
        }
    }

    for (const auto &pair : target)
    {
        cout << pair.second << " ";
    }
    cout << endl;

    return 0;
}