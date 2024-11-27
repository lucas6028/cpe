#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, l;
	int cnt = 0;
	cin >> n >> m >> l;
	vector<vector<int>> adj(n);	
	vector<int> fall(n, 0);
	stack<int> sk;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
	}
	while (l--) {
		int a;
		cin >> a;
		sk.push(a - 1);
	}
	while (!sk.empty()) {
		int to = sk.top();
		sk.pop();
		if (fall[to] == 0) {
			for (int it: adj[to]) {
				sk.push(it);
			}
			fall[to] = 1;
			cnt++;
		}
	}
	/*
	for (int i = 0; i < n; ++i) {
		if (fall[i]) {
			cerr << i + 1 << '\n';
		}
	}
	*/
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
