#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, l;
int arr[105][105];
bool chk(vector<int> v) {
    vector<bool> t(n, false);
    for (int i = 0;i < n-1;i++) {
        int diff = abs(v[i] - v[i + 1]);
        if (diff == 0) continue;
        else if (diff > 1) return 0;
        else if (v[i] < v[i + 1]) {
            if (i + 1 - l < 0) return 0;
            for (int j = i; j > i - l;j--) {
                if (t[j]) return 0;
                t[j] = 1;
            }
        }
        else if (v[i] > v[i + 1]) {
            if (i + l >= n)return 0;
            for (int j = i + 1;j < i + l;j++) {
                if (t[j]) return 0;
                t[j] = 1;
                if (v[j] != v[j + 1]) return 0;
            }
            if (t[i + l]) return 0;
            t[i + l] = 1;
        }
    }
    return 1;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) cin >> arr[i][j];

    int ans = 0;
    //행
    for (int i = 0;i < n;i++) {
        vector<int> arg;
        for (int j = 0;j < n;j++) arg.push_back(arr[i][j]);
        if (chk(arg)) {
            ans++;
          //  cout << i << "행" << '\n';
        }
    }
    //열
    for (int i = 0;i < n;i++) {
        vector<int> arg;
        for (int j = 0;j < n;j++) arg.push_back(arr[j][i]);
        if (chk(arg)) {
            ans++;
            //cout << i << "열" << '\n';
        }
    }
    cout << ans;
}
