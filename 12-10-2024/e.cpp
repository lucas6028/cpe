#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve() {
    string s;
    vector<string> vc;

    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        vc.emplace_back(s);
    }

    int n = vc.size();
    map<string, int> to_id;
    map<int, string> to_string;
    vector<vector<int>> adj(n);

    for (int idx = 0; idx < n; ++idx) {
        // update adj
        for (int i = 0; i < (int)vc[idx].size(); ++i) {
            //cerr << vc[idx] << ":\n";
            for (int c = 0; c < 26; ++c) {
                string ns = vc[idx];
                ns[i] = (char)(c + 'a');
                if (to_id.find(ns) != to_id.end()) {
                    //cerr << ns << "\n";
                    int ri = to_id[ns];
                    adj[ri].push_back(idx);
                    adj[idx].push_back(ri);
                }
            }
        }
        to_id[vc[idx]] = idx;
        to_string[idx] = vc[idx];
    }

    // BFS
    string a, b;
    int T = 0;
    while (cin >> a >> b) {
        if (T) cout << "\n";
        T++;
        if (to_id.find(a) == to_id.end() || to_id.find(b) == to_id.end()) {
            cout << "No solution.\n";
            continue;
        }
        //printf("%lld -> %lld\n", to_id[a], to_id[b]);

        vector<int> visited(n, 0);
        vector<int> parents(n, -1);
        queue<int> q;
        int cnt = 0;
        int source = to_id[a], dest = to_id[b];
        bool ok = false;
        q.push(source);
        while (!q.empty() && !ok) {
            int len = q.size();
            cnt++;
            while (len--) {
                int u = q.front();
                q.pop();
                if (visited[u]) continue;
                if (u == dest) {
                    ok = true;
                    break;
                }
                visited[u] = 1;
                for (int v : adj[u]) {
                    if (parents[v] == -1) {
                        q.push(v);
                        parents[v] = u;
                    }
                }
            }
        }
        if (ok) {
            //cout << cnt << "\n";
            vector<int> res;
            int u = dest;
            while (u != source) {
                res.push_back(u);
                u = parents[u];
            }
            res.push_back(u);
            reverse(res.begin(), res.end());
            for (int it : res) {
                cout << to_string[it] << "\n";
            }
        }
        else {
            cout << "No solution.\n";
        }
    }
}

signed main() {
    solve();
    return 0;
}
