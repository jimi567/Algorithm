#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    vector<int> n;
    
    for (char c : s) n.push_back(c -'0');
    sort(n.begin(), n.end());
    int s = 0;
    for (int i : n) s += i;
    if (n[0] == 0 && s % 3 == 0) {
        for (int i = n.size() - 1; i >= 0; i--) cout << n[i];
    }
    else cout << -1;
}

