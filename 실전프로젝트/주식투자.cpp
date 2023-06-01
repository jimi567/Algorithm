#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc;
int n;
ll arr[100005];
int main() {
    fastIO;
   
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0;i < n;i++) cin >> arr[i];

        ll mx = 0;
        ll ret = 0;
        for (int i = n - 1;i >= 0;i--) {
            mx = max(mx, arr[i]);
            ret += mx - arr[i];
        }
        cout << ret << endl;
    }
}
