#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    if (m <= n - 1) {
        cout << m << "\n";
        return;
    }
    if (m == n) {
        cout << n - 3 << "\n";
        return;
    }
    
    m -= n;
    n -= 3;
    int cnt = 3;
    while (m > 0) {
        m -= cnt - 1;
        cnt++;
        n--;
    }
    cout << n << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
	return 0;
}
