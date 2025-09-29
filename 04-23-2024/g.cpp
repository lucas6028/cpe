#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e6;
int n, m;
int MOD = 1<<20;
int fac[maxn + 1];

void solve() {
    if (m == 0) {
        cout << "0\n";
        return;
    }

    n--;
    n %= 3 * (1<<(m - 1));
    int mod = 1<<m;
    cout << fac[n] % mod << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        fac[i] = (fac[i - 1] + fac[i - 2]) % MOD;
    }
    while (cin >> n >> m) {
        solve();
    }

	return 0;
}
