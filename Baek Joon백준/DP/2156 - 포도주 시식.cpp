#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int arr[10005];
int d[10005][3]; // [i번쨰 잔까지 왔을떄 최대] [이번잔은 몇번쨰 연속으로 마신 잔인가]
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    d[0][0] = 0; d[0][1] = arr[0]; d[0][2] = 0;

    for (int i = 1; i < n; i++) {
        d[i][0] = max({ d[i - 1][0],d[i - 1][1],d[i - 1][2] }); //이번잔은 안마심
        d[i][1] = d[i - 1][0] + arr[i]; //이번잔이 첫번쨰 연속으로 마시는 잔
        d[i][2] += d[i - 1][1] + arr[i]; //이번잔이 두번쨰 연속으로 마시는잔
    }
    cout << max({d[n - 1][0], d[n - 1][1], d[n - 1][2] }); 
}
