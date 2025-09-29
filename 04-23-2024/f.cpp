#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 30;
int dp[maxn + 1][4];
int n;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for (int i = 1; i <= maxn; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1];
        dp[i][3] = dp[i - 1][3] * 2 + dp[i - 1][2];
    }

    while (cin >> n) {
        if (n == 0) break;
        if (n >= 30) cout << dp[30][3] << "\n";
        else cout << dp[n][3] << "\n";
    }

	return 0;
}
