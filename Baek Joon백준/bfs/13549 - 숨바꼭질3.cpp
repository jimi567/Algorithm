#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, m;
int ans;
int arr[100005];
int vis[100005];
int dx[2] = { 1,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<int> q;
    fill(vis, vis + 100005, -1);
    int nx = n;
    q.push(n); vis[n] = 0;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == m) {
            cout << vis[cur];
            break;
        }
        int nx = cur;
        while (cur != 0 && nx < 100001) {
            if (vis[nx] == -1) {
                q.push(nx);
                vis[nx] = vis[cur];
            }
            nx *= 2;
        }
        for (int dir = 0;dir < 2;dir++) {
            int nx = cur + dx[dir];
            if (nx < 0 || nx>=100001) continue;
            if (vis[nx] != -1) continue;
            q.push(nx); 
            vis[nx] = vis[cur] + 1;
        }
    }
}
    
