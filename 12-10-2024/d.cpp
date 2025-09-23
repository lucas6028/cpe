#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> alive(n, 1);

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        a[i].assign(m, 0);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    int d = 0;
    int rem = n;
    int last = 0;
    while (rem && cnt <= 2520) {
        int mn = 251, min_idx = -1, min_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!alive[i]) continue;
            int j = d % (int)(a[i].size());
            if (mn > a[i][j]) {
                mn = a[i][j];
                min_idx = i;
                min_cnt = 1;
            }
            else if (mn == a[i][j]) {
                min_cnt++;
            }
        }

        d++;
        if (min_cnt > 1) {
            cnt++;
            continue;
        }
        rem--;
        alive[min_idx] = 0;
        last = d;
        cnt = 0;
        //printf("Day%d: %d\n", d, min_idx);
    }

    cout << rem << " " << last << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
