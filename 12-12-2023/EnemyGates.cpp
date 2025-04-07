#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	if (m < n) {
		cout << m << '\n';
		return ;
	}
	if (n == m) {
		cout << m - 3 << '\n';
		return ;
	}
	int sum = n - 3;
	int p = n;
	int cnt = 1;
	while (p <= m) {
		sum--;
		p += cnt;
		cnt++;	
	}
	cout << sum + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
