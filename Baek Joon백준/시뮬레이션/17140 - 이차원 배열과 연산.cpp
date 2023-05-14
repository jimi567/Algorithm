#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int r,c,k;
int arr[105][105];
int cc = 3;
int cr = 3;
int cnt[104];

void R() {
    int mx = 0;
    for (int i = 1;i <= cr;i++) {
        vector<int> tmp;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1;j <= cc;j++) {
            if (arr[i][j] == 0) continue;
            if(cnt[arr[i][j]] == 0)tmp.push_back(arr[i][j]);
            cnt[arr[i][j]]++;
        }
        sort(tmp.begin(), tmp.end());
        vector<pair<int, int>> ret;
        for (int c : tmp)ret.push_back({ cnt[c],c });
        sort(ret.begin(), ret.end());

        for (int j = 1;j < 101;j++) arr[i][j] = 0;
        int idx = 1;
        for (auto r : ret) {
            if (idx > 100) break;
            arr[i][idx++] = r.Y;
            if (idx > 100)break;
            arr[i][idx++] = r.X;
        }
        idx--;
        mx = max(mx, idx);
    }
    cc = max(mx, cc);
}
void C() {
    int mx = 0;
    for (int i = 1;i <= cc;i++) {
        vector<int> tmp;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1;j<= cr;j++) {
            if (arr[j][i] == 0) continue;
            if(cnt[arr[j][i]] == 0)tmp.push_back(arr[j][i]);
            cnt[arr[j][i]]++;
        }
        vector<pair<int, int>> ret;
        for (int c : tmp)ret.push_back({ cnt[c],c });
        sort(ret.begin(), ret.end());

        int idx = 1;
        for (int j = 1;j <= 101;j++) arr[j][i] = 0;
        for (auto r : ret) {
            if (idx > 100) break;
            arr[idx++][i] = r.Y;
            if (idx > 100) break;
            arr[idx++][i] = r.X;
        }
        idx--;
        mx = max(mx, idx);
    }
    cr = max(cr, mx);
}

int main() {
    fastIO;
    cin >> r >> c >> k;
    for (int i = 1;i <= cc;i++) {
        for (int j = 1;j <= cr;j++) cin >> arr[i][j];
    }
    int ans = 0;
   
    while (ans <= 100) {
        if (arr[r][c] == k ) break;
        if (cr >= cc) R();
        else C();
        ans++;
    }
    if (ans > 100) cout << -1;
    else cout << ans;
}
