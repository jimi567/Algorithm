#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n;
pair<int, int> task[200005];
int used[200005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0;i < n;i++) {
        int s, t;
        cin >> s >> t;
        task[i] = {s,t};
    }
    sort(task, task + n);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(task[0].Y);
    for (int i = 1;i < n;i++) {
        if (pq.top() <= task[i].X) pq.pop();
        pq.push(task[i].Y);
    }
    cout << pq.size();
}
