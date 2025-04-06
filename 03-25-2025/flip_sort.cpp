#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

void solve() {
    vector<int> vc(n);
    ll cnt = 0;

    for (int i = 0; i < n; ++i) {
        cin >> vc[i];
        //cout << vc[i] << ' ';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vc[j] > vc[j + 1]) {
                swap(vc[j], vc[j + 1]);
                cnt++;
            }
        }
    }
    cout << "Minimum exchange operations : " << cnt << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    while (cin >> n) {
        solve();
    }

	return 0;
}
