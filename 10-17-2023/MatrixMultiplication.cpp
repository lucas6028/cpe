#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define ff first
#define ss second
#define ll long long

map<char, pii> mp;
string s;

void solve() {
	ll sum = 0;
	stack<char> stk;
	char general = 'a';
	if (s.length() == 1) {
		cout << 0 << '\n';
		return ;
	}
	for (char& c : s) {
		if (c == '(' || isalpha(c)) {
			stk.push(c);
		}
		else {
			char cb = stk.top();
			stk.pop();
			char ca = stk.top();
			stk.pop();
			stk.pop(); // pop (
			
			pii a = mp[ca];
			pii b = mp[cb];
			//printf("matrix -> %c:{%d, %d}, %c:{%d, %d}\n", ca, a.ff, a.ss, cb, b.ff, b.ss);
			if (a.ss != b.ff) {
				cout << "error\n";
				return ;
			}
			sum += a.ff * a.ss * b.ss;
			mp[general] = {a.ff, b.ss};
			stk.push(general);
			general++;
			general = (char)general;
		}
	}	
	cout << sum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		mp[c] = {a, b};	
	}
	cin.ignore();

	while (cin >> s) {
		solve();
	}

	return 0;
}
