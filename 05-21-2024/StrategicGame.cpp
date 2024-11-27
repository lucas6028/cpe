#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> dp;

void dfs(int u, int fa) {
	dp[u][0] = 0;
	dp[u][1] = 1;

	for (int v : adj[u]) {
		if (v == fa) {
			continue;
		}
		dfs(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
}

void solve() {
	adj.clear();
	adj.resize(n);
	dp.clear();
	dp.resize(n, vector<int>(2, 0));

	for (int i = 0; i < n; ++i) {
		int a, b, m;
		scanf("%d:(%d)", &a, &m);
		while (m--) {
			cin >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	dfs(0, -1);
	cout << min(dp[0][0], dp[0][1]) << '\n';
}

int main() {
	/*
	ios::sync_with_stdio(0);
	cin.tie(0);
	*/

	while (cin >> n) {
		solve();
	}
}
