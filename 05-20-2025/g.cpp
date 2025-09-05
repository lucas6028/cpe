#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

const int maxn = 10000;
vector<pii> adj[maxn];

struct DSU {
    vector<int> sz, pa;
public:
    explicit DSU(int n) : sz(n, 1), pa(n, -1) {}
    int find(int x) {
        return pa[x] == -1 ? x : pa[x] = find(pa[x]);
    }
    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        sz[rx] += sz[ry], pa[ry] = rx;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    int tot = 0;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u-- ,v--;

        tot += w;
        edges[i] = {w, u, v};
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    sort(edges.begin(), edges.end(), greater<vector<int>>());
    DSU dsu(n);

    int tot_st = 0;
    for (vector<int>& e : edges) {
        if (dsu.find(e[1]) != dsu.find(e[2])) {
            dsu.unite(e[1], e[2]);
            tot_st += e[0];
        }
    }
    cout << tot - tot_st << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}
