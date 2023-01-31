#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
long long d[100][2];// i번째 자리에서 0을 선택했을떄/ 1을선택했을때 이친수의 갯수
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;


    d[1][0] = 0; d[1][1] = 1LL;

    for (int i = 2; i <= n; i++) {
        d[i][0] = d[i - 1][0] + d[i - 1][1]; // 0을택하면 이전 값은 0이던 1이던 상관x
        d[i][1] = d[i - 1][0]; //1을선택했으면 이전값은 무조건 0만가능
    }
    cout << d[n][0] + d[n][1];
}
