#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Interval {
    int s, e, idx;
};

struct DSU {
    vector<int> p;
    DSU(int n=0){ p.resize(n); iota(p.begin(), p.end(), 0); }
    int find(int a){ return p[a]==a ? a : p[a]=find(p[a]); }
    void unite(int a, int b){
        a = find(a); b = find(b);
        if (a==b) return;
        p[b] = a;
    }
};

void process_and_union(unordered_map<int, vector<Interval>> &Amap,
                       unordered_map<int, vector<Interval>> &Bmap,
                       DSU &dsu)
{
    // gather all keys present in either map
    unordered_set<int> keys;
    keys.reserve(Amap.size() + Bmap.size());
    for (auto &kv : Amap) keys.insert(kv.first);
    for (auto &kv : Bmap) keys.insert(kv.first);

    for (int key : keys) {
        auto itA = Amap.find(key);
        auto itB = Bmap.find(key);
        if (itA == Amap.end() || itB == Bmap.end()) continue; // nothing to intersect

        auto &A = itA->second;
        auto &B = itB->second;
        if (A.empty() || B.empty()) continue;

        sort(A.begin(), A.end(), [](const Interval& x, const Interval& y){ return x.s < y.s; });
        sort(B.begin(), B.end(), [](const Interval& x, const Interval& y){ return x.s < y.s; });

        int i = 0, j = 0;
        while (i < (int)A.size() && j < (int)B.size()) {
            const Interval &ai = A[i];
            const Interval &bj = B[j];
            if (ai.e < bj.s) {
                ++i;
            } else if (bj.e < ai.s) {
                ++j;
            } else {
                // intervals intersect (closed), union the rectangles
                dsu.unite(ai.idx, bj.idx);
                // advance the interval that finishes earlier
                if (ai.e < bj.e) ++i; else ++j;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    while ( (cin >> N) ){
        vector<int> x1(N), y1(N), x2(N), y2(N);
        vector<ll> area(N);
        unordered_map<int, vector<Interval>> lefts, rights, bottoms, tops;
        lefts.reserve(N*2); rights.reserve(N*2);
        bottoms.reserve(N*2); tops.reserve(N*2);

        for (int i = 0; i < N; ++i){
            int X, Y, W, H;
            cin >> X >> Y >> W >> H;
            x1[i] = X;
            y1[i] = Y;
            x2[i] = X + W;
            y2[i] = Y + H;
            area[i] = 1LL * W * H;

            lefts[x1[i]].push_back({ y1[i], y2[i], i });
            rights[x2[i]].push_back({ y1[i], y2[i], i });
            bottoms[y1[i]].push_back({ x1[i], x2[i], i });
            tops[y2[i]].push_back({ x1[i], x2[i], i });
        }

        DSU dsu(N);
        // match right==x with left==x (vertical touching)
        process_and_union(rights, lefts, dsu);
        // match top==y with bottom==y (horizontal touching)
        process_and_union(tops, bottoms, dsu);

        // sum areas per component root
        unordered_map<int, ll> compSum;
        compSum.reserve(N*2);
        ll best = 0;
        for (int i = 0; i < N; ++i) {
            int r = dsu.find(i);
            compSum[r] += area[i];
            if (compSum[r] > best) best = compSum[r];
        }
        cout << best << '\n';
    }
    return 0;
}

