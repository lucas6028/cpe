#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void solve() {
	ll n;
	ll b = -2;
	cin >> n;
	string res = "";

	while (n != 0) {
		//int r = n - ((n / b) * b);
		int r = n % b;
		if (r < 0) {
			r = r - b;
		}
		res = to_string(r) + res;
		n = (n - r) / b;
	}
	if (res == "") cout << "0\n";
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}
