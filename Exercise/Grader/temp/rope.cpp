#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxRopePieces(int n, int a, int b, int c) {
    vector<int> dp(n + 1);  // Initialize
    dp[0] = 0;  // Base case: 0 length rope can be achieved with 0 pieces
    
    for (int i = 1; i <= n; ++i) {
        if (i >= a) dp[i] = max(dp[i], dp[i - a] + 1);
        if (i >= b) dp[i] = max(dp[i], dp[i - b] + 1);
        if (i >= c) dp[i] = max(dp[i], dp[i - c] + 1);
    }

    return dp[n] < 0 ? 0 : dp[n];  // If dp[n] is negative, return 0 (not possible)
}

int main() {
    int n ;
    int a, b, c;
    cin >> n >> a >> b >> c;
    cout << maxRopePieces(n, a, b, c) << endl;
    return 0;
}
