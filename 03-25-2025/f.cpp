#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int n, m;
const int INF = 1e18;

void solve() {
    int len = n + m;
    int sum = 0;
    vector<int> a(len);

    for (int i = 0; i < len; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    const int K = min(n, m);
    const int max_sum = 50 * 50;
    const int range = 2 * max_sum + 1;
    
    // dp[k][idx] = true if sum up to (idx - max_sum) using k elements
    vector<vector<int>> dp(K + 1, vector<int>(range, 0));
    dp[0][max_sum] = 1;

    for (int coin : a) {
        vector<vector<int>> ndp = dp;
        for (int k = 0; k < K; ++k) {
            for (int idx = 0; idx < range; ++idx) {
                if (dp[k][idx]) {
                    int nidx = idx + coin;
                    if (nidx >= 0 && nidx < range) {
                        ndp[k + 1][nidx] = 1;
                    }
                }
            }
        }
        swap(dp, ndp);
    }

    int mx = -INF;
    int mn = INF;
    for (int idx = 0; idx < range; ++idx) {
        if (dp[K][idx]) {
            int s = idx - max_sum;
            mx = max(mx, s * (sum - s));
            mn = min(mn, s * (sum - s));
        }
    }
    cout << mx << " " << mn << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m) {
        solve();
    }
    return 0;
}
