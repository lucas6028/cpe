#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int maxn = 1e6;
int n;

/*
void solve() {
    int target = floor(n * n / 2.0);
    int ans = 0;
    vector<int> a(n);

    iota(a.begin(), a.end(), 1);

    do {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += abs(a[i - 1] - i);
        }
        if (sum == target) {
            ans++;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << ans << "\n";
}
*/

signed main() {
    vector<int> dp(maxn + 1, 0);
    dp[1] = dp[2] = 1;
    int base = 2;

    for (int i = 3; i <= maxn; ++i) {
        if (i & 1) {
            dp[i] = dp[i - 1] * i % MOD;
        }
        else {
            dp[i] = dp[i - 2] * base % MOD * base % MOD;
            base++;
        }
    }

    while (cin >> n) {
        cout << dp[n] << "\n";
    }
    return 0;
}
