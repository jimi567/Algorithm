#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc;
int n, b, c;
vector<int> v;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        int in;
        cin >> in;
        v.push_back(in);
    }
    cin >> b >> c;
    ll ans = 0;
    for (int i = 0;i < v.size();i++) {
        ans++; //총감독관
        int p = (v[i] - b);
        if (p <= 0) continue;
        ans += p / c;
        if (p % c != 0) ans++;
    }
    cout << ans;
}
