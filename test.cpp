#include <iostream>
#include <string>

using namespace std;

string int2str (int t) {
    if (t < 10) {
        return "0" + to_string(t);
    }
    return to_string(t);
}

int main()
{
    int H,M,amt;
    cin >> H >> M;
    cin >> amt;

    M += amt;

    H += M / 60;
    if (M >= 60) {
        M %= 60;
    }

    if (H > 24) {
        H %= 24;
    } else if (H == 24) {
        H = 0;
    }

    cout << int2str(H) << " " << int2str(M);
    return 0;
}
