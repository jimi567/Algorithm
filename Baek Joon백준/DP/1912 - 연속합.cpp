#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int a[100001];
int d[100001]; //i번쨰 까지 도달했을때, 연속합의 최대
int mx = -2000;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    d[0] = a[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(d[i - 1] + a[i], a[i]); //여태까지의 합, 새로 시작하는 것 중 최대
        mx = max(mx, d[i]);
    }
    if (mx < a[0]) mx = a[0];
    cout << mx;
}
