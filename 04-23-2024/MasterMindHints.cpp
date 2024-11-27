#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    vector<int> secret(n);
    vector<int> guess(n);
    for (int i = 0; i < n; ++i) {
        cin >> secret[i];
    }
    while (1) {
        vector<bool> visited(n, false);
        bool allZero = true;
        for (int i = 0; i < n; ++i) {
            cin >> guess[i];
            if (guess[i]) {
                allZero = false;
            }
        }
        if (allZero) return ;

        int a = 0, b = 0;
        // calculate a
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                a++;
                guess[i] = -1;
                visited[i] = true;
                continue;
            }
        }
        // calculate b
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (secret[i] == guess[j] && !visited[i]) {
                    b++;
                    guess[j] = -1;
                    visited[i] = true;
                }
            }
        }
        printf("    (%d,%d)\n", a, b);
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int t = 1;
    while (cin >> n && n) {
        cout << "Game " <<  t++ << ":\n";
        solve();
    }
}
