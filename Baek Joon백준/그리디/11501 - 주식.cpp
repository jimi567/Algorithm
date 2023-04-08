#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc;
int n;
ll arr[1000005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;

    while (tc--) {
        cin >> n;
        for (int i = 0;i < n;i++) cin >> arr[i];
        ll mx = arr[n - 1];
        ll ans = 0;
        for (int i = n - 1;i >= 0;i--) {
            mx = max(mx, arr[i]);
            ans += mx - arr[i];
        }
        cout << ans << '\n';
    }
}
