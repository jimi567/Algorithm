#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int dx[8] = { 1,0,-1,0,1,-1,1,-1 };
int dy[8] = { 0,1,0,-1,1,-1,-1,1 };
int arr[15][15];
int ks[15][15];
int tc, n, c, p;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0;i < 15;i++) fill(arr[i], arr[i] + 15, 5);
    cin >> n >> c  >> p;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> ks[i][j];
        }
    }
    vector<tuple<int, int, int>> tree;
    for (int i = 0;i < c;i++) {
        int x, y, a;
        cin >> x >> y >> a;
        tree.push_back({ a,x,y });
    }
    sort(tree.begin(), tree.end());
    while (p--) {
        vector<tuple<int, int, int>> tree2;
        vector<tuple<int, int, int>> dead;
        vector<tuple<int, int, int>> news;
        vector<tuple<int, int, int>> ret;
        for (int i = 0;i < tree.size();i++) {
            int a, x, y;
            tie(a, x, y) = tree[i];
            if (arr[x][y] >= a) {
                arr[x][y] -= a;
                tree2.push_back({ a + 1,x,y });
            }
            else {
                dead.push_back({ a,x,y });
            }
        }
        for (int i = 0;i < dead.size();i++) {
            int a, x, y;
            tie(a, x, y) = dead[i];
            arr[x][y] += a / 2;
        }
        for (int i = 0;i < tree2.size();i++) {
            int a, x, y;
            tie(a, x, y) = tree2[i];
            if (a % 5 == 0) {
                for (int dir = 0;dir < 8;dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (nx <= 0 || nx > n || ny <= 0 || ny > n)continue;
                    news.push_back({ 1,nx,ny });
                }
            }
        }
        for (int i = 0;i < news.size();i++) {
            ret.push_back(news[i]);
        }
        for (int i = 0;i < tree2.size();i++) ret.push_back(tree2[i]);

        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                arr[i][j] += ks[i][j];
            }
        }
        tree = ret;
    }
    
    cout << tree.size();
    
}
    
