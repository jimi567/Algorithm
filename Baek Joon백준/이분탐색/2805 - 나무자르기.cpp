#include <bits/stdc++.h>
using namespace std;
int n, h;
int trees[1000005];

long long cut(long long len) {
    long long sum = 0;
    for (int i = 0;i < n;i++) {
        if(trees[i] > len)
            sum += trees[i] - len;
    }
    return sum;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    for (int i = 0;i < n;i++) cin >> trees[i];

    long long st = 0;
    long long en = 2000000000;
    long long ans = 0;
    while (st < en) {
        long long mid = (st + en + 1) / 2;
        if (cut(mid) >= h) {
            ans = max(ans, mid);
            st = mid;
        }
        else {
            en = mid - 1;
        }
    }
    cout << ans;
}
