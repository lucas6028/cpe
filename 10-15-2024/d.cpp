#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e6;
const int max_x = 1e12;
int is_prime[INF + 1];

void sieve(vector<int>& primes) {
    is_prime[0] = is_prime[1] = 1;
    int sq = sqrt(INF);

    for (int i = 2; i <= sq; ++i) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= INF; j += i) {
                is_prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= INF; ++i) {
        if (!is_prime[i]) {
            primes.push_back(i);
        }
    }
}

signed main() {
    // find prime numbers
    memset(is_prime, 0, sizeof(is_prime));
    vector<int> primes;
    primes.reserve(1000);
    sieve(primes);

    // find almost prime numbers
    vector<int> almost;
    almost.reserve(1000);
    for (const int prime : primes) {
        int x = prime * prime;
        while (x <= max_x) {
            almost.push_back(x);
            x *= prime;
        }
    }
    sort(almost.begin(), almost.end());

    int t;
    cin >> t;
    while (t--) {
        int low, high;
        cin >> low >> high;
        auto l = lower_bound(almost.begin(), almost.end(), low);
        auto r = upper_bound(almost.begin(), almost.end(), high);
        cout << r - l << "\n";
    }

    return 0;
}
