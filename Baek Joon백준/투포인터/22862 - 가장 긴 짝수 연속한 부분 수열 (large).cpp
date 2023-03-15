#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, k;
int ans;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    vector<int> v;
    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    int st = 0;
    int en = 0;
    int len = 0;
    int rm = 0;
    for (;st < n;st++) {
        if (en == n) break;
        while (en < n) {
            if (v[en] % 2 == 1) {
                if (rm < k) {
                    rm++;
                    en++;
                }
                else break;
            }
            else {
                len++;
                en++;
            }
        }
        ans = max(ans, len);
        if (v[st] % 2 == 1) rm--;
        else len--;
    }
    cout << ans;
}
