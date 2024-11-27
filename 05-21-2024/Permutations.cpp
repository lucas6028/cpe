#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fac[21];

void solve() {
	string s;
	string res = "";
	ll k;
	cin >> s >> k;
	ll n = s.length();

	priority_queue<char, vector<char>, greater<char>> pq;
	for (char c : s) {
		pq.push(c);
	}

	for (ll i = 0; i < n; ++i) {
		ll unit = fac[n - i - 1];
		ll p = k / unit;
		k -= p * unit;
		//cerr << "p: " << p << '\n';
		queue<char> q;
		while (p--) {
			if (pq.empty()) {
				//cerr << "Bug: pq.empty()\n";
				break;
			}
			q.push(pq.top());
			pq.pop();	
		}
		res += pq.top();
		//cerr << pq.top();
		pq.pop();
		while (!q.empty()) {
			pq.push(q.front());
			q.pop();
		}
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fac[0] = 1;
	for (ll i = 1; i < 21; ++i) {
		fac[i] = fac[i - 1] * i;
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
