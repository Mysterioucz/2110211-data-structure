#include <iostream>
#include <set>
#include <fstream>
using namespace std;

int main()
{
    set<int> s={3,4,5,6};
    cout << *s.upper_bound(2) << endl;
    cout << *s.lower_bound(2) << endl;
    return 0;
}