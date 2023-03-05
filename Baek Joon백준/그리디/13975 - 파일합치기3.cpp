#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t, n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            pq.push(num);
        }
        ll ans = 0;
        while (pq.size() > 1) {
            ll c1 = pq.top(); pq.pop();
            ll c2 = pq.top(); pq.pop();
            ans += c1 + c2;
            pq.push(c1 + c2);
        }
        cout << ans << '\n';

    }
}

