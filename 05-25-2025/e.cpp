#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second

const int INF = 1e9 + 7;
int n;
int x, y, k;
vector<vector<int>> dist;

void solve() {
    vector<int> seen(n, 0);
    priority_queue<int, vector<int>, greater<int>> res;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});

    // BFS with min heap
    while (!pq.empty() && (int)res.size() < k) {
        int w = pq.top().ff;
        int parent = pq.top().ss;
        pq.pop();
        //cout << "DEBUG: " << w << ' ' << parent << '\n';

        if (parent == y) {
            res.push(w);
        }
        if (++seen[parent] > k) {
            continue;
        }

        for (int child = 0; child < n; ++child) {
            if (dist[parent][child] == -1) continue;

            pq.push({w + dist[parent][child], child});
        }
    }

    if (k > (int)res.size()) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < k - 1; ++i) res.pop();
    cout << res.top() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        dist.assign(n, vector<int>(n, -1));

        cin >> x >> y >> k;
        x--, y--;

        int u, v, l;
        while (m--) {
            cin >> u >> v >> l;
            dist[u - 1][v - 1] = l;
        }
        solve();
    }

	return 0;
}
