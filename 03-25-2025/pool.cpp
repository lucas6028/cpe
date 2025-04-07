#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pii pair<ll, ll>
#define ff first
#define ss second

/*
bool cmp(pii& pa, pii& pb) {
    return pa.ff < pb.ff;
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
*/

void solve() {
    ll capacity, temperature;
    ll n;

    cin >> capacity >> temperature; 
    cin >> n;

    ll half = ceil((ld)capacity / 2.0);
    vector<pii> jars(n);
    // Calculate prefix sum
    vector<ll> prefix(n + 1, 0), prefixVol(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> jars[i].ff >> jars[i].ss;
        prefix[i + 1] = prefix[i] + (jars[i].ff * jars[i].ss);
        prefixVol[i + 1] = prefixVol[i] + jars[i].ff;
    }

    int start = -1, end = -1;
    ld diff = 10.0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ll tot = prefix[j + 1] - prefix[i];
            ll vol = prefixVol[j + 1] - prefixVol[i];
            //cerr << tot << ' ' << vol << '\n';

            if (vol < half) continue;
            if (vol > capacity) break;

            ld curr = abs((ld)tot / (ld)vol - (ld)temperature);
            //cerr << "curr: " << curr << '\n';
            if (curr <= 5.0 && curr < diff) {
                diff = curr;
                start = i;
                end = j;
            }
        }
    }
    if (diff == 10.0) {
        cout << "Not possible\n";
    }
    else {
        cout << start << ' ' << end << '\n';
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
