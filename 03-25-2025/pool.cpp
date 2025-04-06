#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pii pair<ll, ll>
#define ff first
#define ss second

bool cmp(pii& pa, pii& pb) {
    return pa.ss < pb.ss;
}

void helper(size_t p, vector<pii>& vc, ll totVol, ll totTemp, ll start, ll capacity, ll temperature, ld& diff, pii& res) {
    if (p == vc.size()) return;
    helper(p + 1, vc, totVol, totTemp, start, capacity, temperature, diff, res);

    totVol += vc[p].ff * vc[p].ss;
    totTemp += vc[p].ss;

    ld curr = (ld)totVol / (ld)totTemp;
    if (curr > temperature) return;

    if (diff > curr) {
        diff = curr;
        res.ff = start == -1 ? p : start;
        res.ss = p;
    }
    helper(p + 1, vc, totVol, totTemp, start, capacity, temperature, diff, res);
}

void solve() {
    ll capacity, temperature;
    ll n;

    cin >> capacity >> temperature; 
    cin >> n;

    vector<pii> vc(n);
    for (ll i = 0; i < n; ++i) {
        cin >> vc[i].ff >> vc[i].ss;
    }
    sort(vc.begin(), vc.end(), cmp);

    pii res;
    ld diff = 5.1;
    helper(0, vc, -1, 0, 0, capacity, temperature, diff, res);
    if (diff > 5.0) {
        cout << "Not possible\n";
    }
    else {
        cout << res.ff << ' ' << res.ss << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

	return 0;
}
