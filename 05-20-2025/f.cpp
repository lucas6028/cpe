# include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int n, m;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    x--, y--;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
    }

    // dijkstra
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, x);
    vector<int> count(n, 0);

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        count[u]++;

        if (u == y && count[u] <= k) {
            if (k == count[u]) {
                cout << w << "\n";
                return;
            }
        }
        if (count[u] > k) continue;

        for (pii& pa : adj[u]) {
            pq.emplace(w + pa.second, pa.first);
        }
    }
    cout << -1 << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        solve();
    }

	return 0;
}
