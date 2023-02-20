#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, m;
int arr[100005];
int ans = 0x7f7f7f7f;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    for (int i = 0; i < n; i++) cin >> arr[i];
   
    int en = 0;
    int sum = arr[0];
    for (int st = 0; st < n; st++) {
        while (sum < m && en != n) sum += arr[++en];
        //cout << sum << " " << st << " " << en << endl;
        if (en == n) break;
        ans = min(ans, en - st+1);
        sum -= arr[st];
    }
    if (ans == 0x7f7f7f7f) cout << 0;
    else cout << ans;
}
