#include <bits/stdc++.h>
using namespace std;

void solve() {
    set<string> st;
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        string token;
        while (ss >> token) {
            string str = "";
            //cerr << "tmp: " << token << '\n';

            for (char& c : token) {
                if (isalpha(c)) {
                    c = tolower(c);
                    str += c;
                }
                else {
                    st.insert(str);
                    str = "";
                }
            }

            if (str != "") {
                st.insert(str);
            }
        }
    }

    for (auto& x : st) {
        if (x == "") continue;
        for (size_t i = 0; i < x.length(); ++i) {
            if (isalpha(x[i])) {
                cout << x[i];
            }
        }
        cout << '\n';
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

    solve();

	return 0;
}
