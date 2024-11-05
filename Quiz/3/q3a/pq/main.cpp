// #include <iostream>
// #include <cmath>

// using namespace std;

// int main(){
//     int n,k,p,q;
//     cin >> n >> k;
//     cin >> p >> q;
//     while(p!=q){
//         if(p>q) p=(p-1)/k;
//         else q=(q-1)/k;
//     }
//     cout << p << endl;
//     return 0;
// }
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    set<int> s;
    long long q, p;
    cin >> p >> q;
    s.insert(p);
    while (p > 0)
    {
        p = (p - 1) / k;
        s.insert(p);
    }
    while (q > 0)
    {
        if (s.find(q) != s.end())
        {
            break;
        }
        q = (q - 1) / k;
    }
    cout << q;
    return 0;
}