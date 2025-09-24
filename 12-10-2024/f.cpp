#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int INF = 1e9;
int C, X, Y, Z;
int dp[152][152][52];

int f(int c, int y, int z) {
    if (c == 0) return 0;
    if (y < 0 || z < 0) return INF;
    int &ans = dp[c][y][z];
    if (ans != -1) return ans;
    ans = INF;

    int bought = C - c;
    int x = X + Y * 5 + Z * 10 - 8 * bought;
    if (x < 0) return INF;

    // [10]
    if (z >= 1) {
        ans = min(ans, 1 + f(c - 1, y, z - 1));
    }
    // [5,5]
    if (y >= 2) {
        ans = min(ans, 2 + f(c - 1, y - 2, z));
    }
    // [5,1,1,1]
    if (y >= 1 && x >= 3) {
        ans = min(ans, 4 + f(c - 1, y - 1, z));
    }
    // [10,1,1,1]
    if (z >= 1 && x >= 3) {
        ans = min(ans, 4 + f(c - 1, y + 1, z - 1));
    }
    // [1]*8
    if (x >= 8) {
        ans = min(ans, 8 + f(c - 1, y, z));
    }

    return ans;
}

void solve() {
    cin >> C >> X >> Y >> Z;
    memset(dp, -1, sizeof(dp));

    cout << f(C, Y, Z) << "\n";
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
