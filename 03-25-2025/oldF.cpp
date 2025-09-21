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
    sort(a.begin(), a.end());

    // calculate min_sum and max_sum
    int min_sum = 0, max_sum = 0;
    for (int i = 0; i < len; ++i) {
        if (min_sum + a[i] < min_sum) {
            min_sum += a[i];
        }
        else {
            break;
        }
    }
    for (int i = len - 1; i >= 0; --i) {
        if (max_sum + a[i] > max_sum) {
            max_sum += a[i];
        }
        else {
            break;
        }
    }
    int K = min(n, m);
    unordered_map<int, vector<bool>> dp;

    // initialize map dp
    for (int s = min_sum; s <= max_sum; ++s) {
        dp[s].assign(K + 1, 0);
    }
    dp[0][0] = 1;

    for (int coin : a) {
        for (int k = 0; k < K; ++k) {
            for (int s = min_sum; s <= max_sum; ++s) {
                if (dp[s][k] && s + coin <= max_sum && s + coin >= min_sum) {
                    dp[s + coin][k + 1] = 1;
                }
            }
        }
    }

    int mx = -INF;
    int mn = INF;
    for (int s = min_sum; s <= max_sum; ++s) {
        if (dp[s][K]) {
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
