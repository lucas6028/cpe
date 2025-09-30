#include <bits/stdc++.h>
using namespace std;

#define int long long 

int n, m, k;
int dp[51][51];

void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int j = 1; j <= k; ++j) {
        for (int s = 1; s <= n; ++s) {
            for (int w = 1; w <= min(m, s); ++w) {
                dp[j][s] += dp[j - 1][s - w];
            }
        }
    }
    cout << dp[k][n] << "\n";
}

signed main() {
    while (cin >> n >> k >> m) {
        solve();
    }
    return 0;
}
