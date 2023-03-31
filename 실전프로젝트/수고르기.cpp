#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc, n, m;
int arr[100005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 0;i < n;i++) cin >> arr[i];
        sort(arr, arr + n);
        int ans = 0x7f7f7f7f;
        int en = 1;
        for (int st = 0;st < n;st++) {
            while (en < n && arr[en] - arr[st] < m) en++;
            if (en >= n) break;
            if (arr[en] - arr[st] == m) {
                ans = arr[en] - arr[st];
                break;
            }
            ans = min(ans, arr[en] - arr[st]);
        }
        cout << ans << '\n';
    }
}
