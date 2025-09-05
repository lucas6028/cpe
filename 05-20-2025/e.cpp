#include <bits/stdc++.h>
using namespace std;

#define int long long

int target;

void solve() {
    vector<int> coins = {1, 5 ,10, 25, 50};
    vector<int> f(target + 1, 0);
    f[0] = 1;

    for (int coin : coins) {
        for (int i = 0; i + coin <= target; ++i) {
            f[i + coin] += f[i];
        }
    }

    if (f[target] == 1) {
        cout <<  "There is only 1 way to produce " << target << " cents change.\n";
    }
    else {
        cout <<  "There are " << f[target] << " ways to produce " << target << " cents change.\n";
    }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    while (cin >> target) {
        solve();
    }

	return 0;
}
