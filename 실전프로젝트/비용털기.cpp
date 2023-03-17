#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc, n,p;
int arr[10005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n >> p;
        for (int i = 0;i < n;i++) cin >> arr[i];
        sort(arr, arr + n);
        int st = 0;
        int en = n - 1;
        while (st < en) {
            if (arr[en] + arr[st] == p) break;
            else if (arr[en] + arr[st] > p) en--;
            else st++;
        }
        cout << arr[st] << " " << arr[en] << '\n';
    }
}
