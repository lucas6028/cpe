#include <bits/stdc++.h>
using namespace std;

void helper(int n, int p, vector<vector<int>>& res, vector<int>& vc) {
	if (n <= 1) return;
	//cout << n << ' ' << p << '\n';
	int sq = sqrt(n);

	while (p <= sq) {
		if (n % p == 0) {
			vc.push_back(p);
			vc.push_back(n / p);
			res.push_back(vc);
			vc.pop_back();
			helper(n / p, p, res, vc);
			vc.pop_back();
		}
		p++;
	}
}

void solve(int n) {
	if (n < 2) {
		cout << 0 << '\n';
		return;
	}
	vector<vector<int>> res;
	vector<int> vc;
	helper(n, 2, res, vc);
	cout << res.size() << '\n';
	sort(res.begin(), res.end());
	for (auto& v : res) {
		for (int it: v) {
			cout << it << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n && n) {
		solve(n);
	}
}
