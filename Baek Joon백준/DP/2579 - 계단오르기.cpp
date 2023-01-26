
//현재 존재하는 계단이 몇번 연속으로 1단점프로 도달한 곳인지 나눠서 생각하는게 포인트
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int s[305];
int n;
int dp[305][3]; //점수, 몇번연속으로 1단점프했는지
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    dp[1][1] = s[1];
    dp[1][2] = 0;
    dp[2][1] = s[2];
    dp[2][2] = s[1] + s[2]; //2번연속 1단점프한것이므로 1번째 점수랑 2번째점수 합
    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s[i]; //1단점프, 2단점프중 점수가 최대인것을 골라야됨
        dp[i][2] = dp[i - 1][1] + s[i];
    }
    cout << max(dp[n][1], dp[n][2]);
} 
