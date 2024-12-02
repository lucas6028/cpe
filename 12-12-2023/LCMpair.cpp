#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define pll pair<long, long>
#define ff first
#define ss second
#define mod 1e9+7

void solve() {
	ll n;
	ll lcm = 1;
	ll sum = 0;
	cin >> n;
	vector<pll> vc(n);
	for (ll i = 0; i < n; ++i) {
		cin >> vc[i].ff >> vc[i].ss;
		lcm *= round(vc[i].ff, vc[i].ss);
	}
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
