#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int m,n;
int ans;

void Prime(int m,int n) {
    vector<bool> state(n+1, true);
    state[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (!state[i]) continue;
        for (int j = i * i; j <= n; j += i) state[j] = false;
    }
    for (int i = m; i <= n; i++) {
        if (state[i]) cout << i << '\n';
    }
    
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    Prime(m, n);
}
