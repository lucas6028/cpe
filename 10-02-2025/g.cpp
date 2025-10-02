#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int INF = 1e10;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> dist(n, vector<int>(n, INF));
    vector<int> alive(n, 0);
    vector<int> x(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    reverse(x.begin(), x.end());

    int ans = 0;
    alive[x[0]] = 1;
    dist[x[0]][x[0]] = 0;
    for (int t = 1; t < n; ++t) {
        alive[x[t]] = 1;

        // update new dist
        for (int i = 0; i < n; ++i) {
            if (!alive[i]) continue;
            dist[x[t]][i] = grid[x[t]][i];
            dist[i][x[t]] = grid[i][x[t]];
        }

        // run APSP
        for (int j = 0; j < n; ++j) {
            if (!alive[j]) continue;
            for (int k = 0; k < n; ++k) {
                if (!alive[k]) continue;
                dist[x[t]][j] = min(dist[x[t]][j], dist[x[t]][k] + dist[k][j]);
                dist[j][x[t]] = min(dist[j][x[t]], dist[j][k] + dist[k][x[t]]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!alive[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (!alive[j] || i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][x[t]] + dist[x[t]][j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (!alive[i]) continue;
            for (int j = 0; j < n; ++j) {
                if (!alive[j]) continue;
                ans += dist[i][j];
            }
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
