#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int mSize, idx;
    cin >> mSize >> idx;
    string res = "";
    int l = (2 * idx + 1), r = (2 * idx + 2), i = 0, count = 0;
    while (i < mSize)
    {
        if ((i != idx) && !(i >= l && i <= r))
        {
            res += to_string(i) + " ";
            count++;
        }
        if (i == l)
        {
            i = r + 1;
            l = 2 * l + 1;
            r = 2 * r + 2;
        }
        else
        {
            i++;
        }
    }
    cout << count << endl;
    cout << res;
    return 0;
}