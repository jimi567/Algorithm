#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>,greater<int>> pq;
    cin >> n;
    for (int i = 0;i < n;i++) {
        int t;
        cin >> t;
        pq.push(t);
    }
    int sum = 0;
    int ans = 0;
    while (pq.size()>1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum = a + b;
        ans += sum;
        pq.push(sum);
    }
    cout << ans;
}
