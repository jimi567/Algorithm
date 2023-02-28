#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;
int vis[2000005];
int dx[2];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;
    dx[0] = u; dx[1] = -d;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == g) {
            cout << vis[cur] - 1;
            return 0;
        }
        for (int i = 0;i < 2;i++) {
            int nx = cur + dx[i];
            if (nx<1 || nx > f || vis[nx] != 0) continue;
            q.push(nx);
            vis[nx] = vis[cur] + 1;
        }

    }
    cout << "use the stairs";
}
