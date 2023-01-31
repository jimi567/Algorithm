#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int d[1005]; // 2x i 직사각형을 채우는 방법의 수
int mod = 10007;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    // d[k] = d[k-1](왼쪽 끝 1x2) +d[k-2](왼쪽 끝 2x2) +  d[k-2](왼쪽 끝 2x1)
    d[1] = 1; d[2] = 3;
    for (int i = 3; i <= n; i++) d[i] = (d[i - 1] + d[i - 2] + d[i - 2] )% mod;
    cout << d[n];
}
