#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 50001;
int adj[maxn];
int f[maxn];
int visited[maxn];

void findCycle(int u) {
    stack<int> stk;
    int v = adj[u];
    stk.push(u);
    while (v != u) {
        stk.push(v);
        v = adj[v];
    }

    int len = stk.size();
    while (!stk.empty()) {
        v = stk.top();
        stk.pop();
        f[v] = len;
        visited[v] = 2;
    }
}

int dfs(int u) {
    if (visited[u] == 2) {
        return f[u];
    }
    if (visited[u] == 1) {
        findCycle(u);
        return f[u];
    }

    int v = adj[u];
    visited[u] = 1;
    dfs(v);
    if (visited[u] == 1) {
        f[u] = 1 + f[v];
    }
    visited[u] = 2;

    return f[u];
}

void solve() {
    int n;
    cin >> n;

    memset(adj, 0, sizeof(adj));
    memset(f, 0, sizeof(f));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u] = v;
    }

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            dfs(i);
        }
    }
    
    int start = -1, sz = 0;
    for (int i = 0; i < n; ++i) {
        if (f[i] > sz) {
            start = i;
            sz = f[i];
        }
    }
    cout << start + 1 << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        solve();
    }

	return 0;
}
