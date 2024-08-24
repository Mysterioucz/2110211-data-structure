#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void jump(vector<int> &v, int n)
{   // solve using Dynamic Programming
    int score = v[0], i = 0;
    while (i < n)
    {
        score += max(max(v[i + 1], v[i + 2]), v[i + 3]);
        // if ((v[i + 1] >= 0) && (v[i + 2] >= 0) && (v[i + 3] >= 0))
        // {
        //     if (max(max(v[i + 1], v[i + 2]), v[i + 3]) == v[i + 1])
        //     {
        //         i += 1;
        //     }
        //     else if (max(max(v[i + 1], v[i + 2]), v[i + 3]) == v[i + 2])
        //     {
        //         i += 2;
        //     }
        //     else
        //     {
        //         i +=3;
        //     }
        // }
        // else
        // {
        //     if (max(max(v[i + 1], v[i + 2]), v[i + 3]) == v[i + 3])
        //     {
        //         i += 3;
        //     }
        //     else if (max(max(v[i + 1], v[i + 2]), v[i + 3]) == v[i + 2])
        //     {
        //         i += 2;
        //     }
        //     else
        //     {
        //         i += 1;
        //     }
        // }
    }
    cout << score << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    int min = (*min_element(v.begin(), v.end())) - 1;
    for (int i = 0; i < 3; i++)
    {
        v.push_back(min);
    }
    jump(v, n);
}