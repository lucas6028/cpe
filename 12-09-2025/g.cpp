#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int n, m;
const int INF = 1e9;

struct Dinic {
    struct Edge {
        int to, rev, cap;
    };

    int n, inf = 1e17;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    Dinic(int _n) : n(_n), adj(n), level(n), ptr(n) {}

    void add(int a, int b, int c) {
        adj[a].push_back({b, (int)adj[b].size(), c});
        adj[b].push_back({a, (int)adj[a].size() - 1, 0});
    }
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q; q.push(s);
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(auto& e: adj[curr]) {
                if(e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[curr] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    int dfs(int curr, int t, int flow) {
        if(flow == 0 || curr == t) return flow;
        for(int& cid = ptr[curr]; cid < (int)adj[curr].size(); cid++) {
            auto& e = adj[curr][cid];
            if(e.cap > 0 && level[e.to] == level[curr] + 1) {
                int temp = dfs(e.to, t, min(flow, e.cap));
                if(temp > 0) {
                    e.cap -= temp;
                    adj[e.to][e.rev].cap += temp;
                    return temp;
                }
            }
        }
        return 0;
    }
    int maxflow(int s, int t) {
        int flow = 0;
        while(bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while(int temp = dfs(s, t, inf)) {
                flow += temp;
            }
        }
        return flow;
    }
};

void solve() {
    vector<pii> edges;

    for (int i = 0; i < m; ++i) {
        char c;
        int u, v;
        cin >> c >> u >> c >> v >> c;
        edges.push_back({u, v});
    }

    if (m == 0) {
        if (n == 1) cout << "1\n";
        else cout << "0\n";
        return;
    }

    int ans = INT_MAX;

    for (int i = 1; i < n; ++i) {
        Dinic din(n * 2);
        for (int u = 0; u < n; ++u) {
            din.add(u, u + n, 1);
        }
        for (const pii& e : edges) {
            din.add(e.first + n, e.second, INF);
            din.add(e.second + n, e.first, INF);
        }
        ans = min(ans, din.maxflow(n, i));
    }

    if (ans > n) {
        if (m == n * (n - 1) / 2) cout << n << "\n";
        else cout << "0\n";
        return;
    }

    cout << ans << "\n";
}

signed main() {
    while (cin >> n >> m) {
        solve();
    }
    return 0;
}
