//크루스칼 알고리즘 + 유니온 파인드
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//가중치 시작 도착
priority_queue< tuple<int, int, int>,
    vector < tuple<int, int, int>>,
    greater <tuple<int,int,int>>> pq;
int v, e;

int p[10005];

int getParent(int v) {
    if (p[v] == v) return v;
    return p[v] = getParent(p[v]);
}

bool is_same_group(int a, int b) {
    a = getParent(a), b = getParent(b);
    if (a == b) return 1;
    return 0;
}
void uni(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return;
    if (p[a] < p[b]) {
        p[b] = p[a];
    }
    else p[a] = p[b];
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 1;i < 10001;i++) p[i] = i;
    for (int i = 1;i <= e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c,a,b});
    }
    int ans = 0;
    vector<tuple<int, int, int>> ret;
    while (ret.size() < v-1) {
        int a, b, c;
        tie(c, a, b) = pq.top(); pq.pop();
        if (is_same_group(a, b)) continue;
        uni(a, b);
        ans += c;
        ret.push_back({ c,a,b });
    }
    cout << ans;
}
//프림 알고리즘
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
//adj[정점1] = {가중치,정점2}
vector<pair<int,int>> adj[10005];
int v, e;
bool vis[10005];
int ans = 0;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 1;i <= e;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ c,b });
        adj[b].push_back({ c,a });
    }
    //가중치, 도착정점
    priority_queue < pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    
    for (auto nxt : adj[1]) {
        pq.push(nxt);
    }
    vis[1] = 1;
    int cnt = 0;
    while (cnt < v -1) {
        auto cur = pq.top(); pq.pop();
        int b, c;
        tie(c, b) = cur;
        if (vis[b]) continue;
        ans += c;
        cnt++;
        vis[b] = 1;
        for (auto nxt : adj[b]) {
            pq.push(nxt);
        }
    }
    cout << ans;
}
