#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc;
int n;
vector<string> split(string str) {
    vector<string> tokens;
    string token;
    for (char c : str) {
        if (c == ' ') {
            tokens.push_back(token);
            token.clear();
        }
        else {
            token += c;
        }
    }
    tokens.push_back(token);
    return tokens;
}
bool isAlphaString(string st) {
    for (char c : st) {
        if (!isalpha(c)) return false;
    }
    return true;
}
bool chk(vector<string> v) {
    if (v.size() != 12) return false;
    string log[4] = { "line_name","product_name","error_level","message" };
    int idx = 0;
    for (int i = 0;i < 12;i++) {
        if (i % 3 == 0) {
            if (v[i] != log[idx++]) return false;
        }
        else if (i % 3 == 1) {
            if (v[i] != ":") return false;
        }
        else {
            if (!isAlphaString(v[i])) return false;
        }
    }
    return true;
}
int main(void) {
	fastIO;
	cin >> tc;
    while (tc--) {
        int n, cnt = 0;
        cin >> n;
        cin.ignore();
        vector<string> logs(n);
        for(int i=0;i<n;i++) {
            getline(cin, logs[i]);
        }
        for (int i = 0;i < n;i++) {
            if (logs[i].size() > 100) continue;
            vector<string> parse = split(logs[i]);
            if (chk(parse)) cnt++;
        }
        cout << n - cnt << endl;
    }
    return 0;
}
