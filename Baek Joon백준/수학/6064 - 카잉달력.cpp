#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int t;
int m, n, x, y;

int gcd(int a, int b) {
    while (b > 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        int ans = -1;
        cin >> m >> n >> x >> y;
        int l = lcm(n, m);
        //cout << l << '\n';
        if (x == m) x = 0;
        if (y == n) y = 0;
        for (int i = y; i <= l; i+=n) {
            if (i == 0) continue;
            if (i % m == x && i % n == y) ans = i;
        }
        cout << ans <<'\n';
    }
}
