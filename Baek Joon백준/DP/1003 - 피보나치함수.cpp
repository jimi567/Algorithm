#include <bits/stdc++.h>
using namespace std;
int t,n;
int d0[45];
int d1[45];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    d0[0] = 1; d0[1] = 0;
    d1[0] = 0; d1[1] = 1;

    for (int i = 2; i <= 40; i++) {
        d0[i] = d0[i - 1] + d0[i - 2];
        d1[i] = d1[i - 1] + d1[i - 2];
    }
    while (t--) {
        cin >> n;
        cout << d0[n] << ' ' << d1[n] << '\n';
    }
    
}
