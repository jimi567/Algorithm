#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int arr[1005];
int d[1005][2][31]; // [i번쨰까지 왔을떄 최댓값][자두의 위치][이동횟수]
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];


    if (arr[0] == 1) d[0][0][0] = 1;
    else d[0][1][1] = 1; 


    //자두 첫위치는 1
    for (int i = 1; i < n; i++) {
        for (int j = 0;j<= m && j<=i; j++) { //이동횟수는 m이하이면서 , i이하여야됨 (초당 한번밖에 못움직임);
            if (arr[i] == 1) { //이번에 자두가 떨어지는 자리가 1
                if (j == 0) { //이동횟수가 0일 경우
                    d[i][0][j] = d[i - 1][0][j] + 1;
                    d[i][1][j] = d[i - 1][1][j];
                    continue;
                }
                d[i][0][j] = max(d[i - 1][0][j], d[i - 1][1][j - 1]) + 1;
                d[i][1][j] = max(d[i - 1][1][j], d[i - 1][0][j - 1]);
            }
            else { //자두가 떨어지는 자리가 2
                if (j == 0) { 
                    d[i][1][j] = d[i - 1][1][j] + 1;
                    d[i][0][j] = d[i - 1][0][j];
                    continue;
                }
                d[i][1][j] = max(d[i - 1][1][j], d[i - 1][0][j - 1]) + 1;
                d[i][0][j] = max(d[i - 1][0][j], d[i - 1][1][j - 1]);
            }
        }
    }

    int ans0 = *max_element(d[n - 1][0],d[n-1][0] + m+1);
    int ans1 = *max_element(d[n - 1][1],d[n-1][1] + m+1);
    cout << max(ans0, ans1);
}
