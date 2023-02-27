#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1005];
int dp[1005][2]; //{i번째 수가 최대일때의 부분수열의 길이 최대,최장부분수열에서 이전값 인덱스}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)cin >> arr[i];
    int ans = 0;//최장증가부분수열의 길이
    int ansIdx = 0; //최장증가부분수열의 마지막 인덱스
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1; //부분수열은 본인을 포함함
        dp[i][1] = -1; //이전인덱스를 -1로 초기화
        for (int j = 0; j < i; j++) {
            if ( arr[j] < arr[i] && dp[i][0] < dp[j][0] + 1) {  
                dp[i][0] = dp[j][0] + 1;
                dp[i][1] = j;
            }
        }
        if (ans < dp[i][0]) {
            ans = dp[i][0];
            ansIdx = i;
        }
    }
    cout << ans << '\n';
    int idx = ansIdx;
    vector<int> v;
    while (idx != -1) { //부분수열에서 이전인덱스가 존재하지않을때까지
        v.push_back(arr[idx]);
        idx = dp[idx][1];
    }
    for (vector<int>::iterator i = v.end()-1; i >= v.begin(); i--) cout << *i << " "; //벡터 역순으로 출력
}
