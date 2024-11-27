#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
map<ll, ll> mp;

void solve() {
	if (n > 30) {
		cout << (ll)mp[30] << '\n';
	}	
	else {
		cout << (ll)mp[n] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<ll> fac(31, 1);
	for (ll i = 1; i < 10; ++i) {
		fac[i] = fac[i - 1] * i;
	}

	mp[0] = 0, mp[1] = 0, mp[2] = 0;
	mp[3] = 1;
	for (ll i = 4; i < 31; ++i) {
		ll l = 0;
		while (i - l > 2) {
			ll u = i - l - 3;
			mp[i] += fac[u + l + 1] / (fac[u + 1] * fac[l]);
			l++;
		}
	}

	while (cin >> n && n) {
		solve();	
	}
}
