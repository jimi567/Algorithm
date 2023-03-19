#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, m;
int arr[1005][1005];
int ans = 0x7f7f7f7f;
vector<int> idx;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        idx.push_back(0);
        for (int j = 0;j < m;j++) cin >> arr[i][j];
    }
    for (int i = 0;i < n;i++) sort(arr[i], arr[i] + m);

    
    while (1) {
        int mxtm;
        int mntm;
        int mx = -1;
        int mn = 0x7f7f7f7f;
        for (int i = 0;i < n;i++) {
            if (mn > arr[i][idx[i]]) {
                mn = arr[i][idx[i]];
                mntm = i;
            }
            if (mx < arr[i][idx[i]]) {
                mx = arr[i][idx[i]];
                mxtm = i;
            }
        }
        ans = min(ans, mx-mn);
        idx[mntm] += 1;
        if (idx[mntm] == m) break;
    }
    cout << ans;
}
    
