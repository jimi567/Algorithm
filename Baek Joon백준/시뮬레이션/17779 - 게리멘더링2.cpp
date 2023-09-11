//5번 영역 구할때 bfs활용
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int n;
int arr[22][22];
int area[22][22];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


void SetArea(int a, int b, int c, int d,int k) {

    for (int i = a;i <= b;i++) {
        for (int j = c;j <= d;j++) {
            if (area[i][j] != 0) continue;
            area[i][j] = k;
        }
    }
}

int getDiff(int x, int y, int d1, int d2) {
    
    memset(area, 0, sizeof(area));

    int sum[5] = { 0, };
    //경계선 긋기
    for (int i = 0;i <= d1;i++) {
        area[x + i][y - i] = 5;
    }
    for (int i = 0; i <= d2;i++) {
        area[x + i][y + i] = 5;
    }
    for (int i = 0;i <= d2;i++) {
        area[x + d1 + i][y - d1 + i] = 5;
    }
    for (int i = 0;i <= d1;i++) {
        area[x + d2 + i][y + d2 - i] = 5;
    }
    //경계선 내부 채우기 bfs
  
    
    queue<pair<int, int>> q;
    //bfs시작지점 - 5번 구역으로 가능한 x,y의 평균값 활용(두 바운더리의 합이 홀수일때 주의)
    if ((x + x + d1 + d2) % 2) {
        q.push({ (x + x + d1 + d2) / 2 + 1,(y - d1 + y + d2) / 2 });
        area[(x + x + d1 + d2) / 2 + 1][(y - d1 + y + d2) / 2] = 5;
    }
    if ((y - d1 + y + d2) % 2) {
        q.push({ (x + x + d1 + d2) / 2 ,(y - d1 + y + d2) / 2 + 1 });
        area[(x + x + d1 + d2) / 2][(y - d1 + y + d2) / 2 + 1] = 5;
    }
    
    if (q.empty()) {
        q.push({ (x + x + d1 + d2) / 2,(y - d1 + y + d2) / 2 });
        area[(x + x + d1 + d2) / 2][(y - d1 + y + d2) / 2] = 5;
    }

    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (!(nx>x && nx<x + d1 + d2 && ny>y - d1 && ny<y + d2)) continue;
            if (area[nx][ny] == 5) continue;
            q.push({ nx,ny }); 
            area[nx][ny] = 5;
        }
    }
  
    
    //1~4구역 셋팅
    SetArea(1, x + d1 - 1, 1, y, 1);
    SetArea(1, x + d2, y - 1, n, 2);
    SetArea(x + d1, n, 1, y - d1 + d2 - 1, 3);
    SetArea(x + d2 - 1, n, y - d1 + d2, n, 4);
    
    //인구수 구하기
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
             sum[area[i][j] - 1] += arr[i][j];
        }
    }
    int mn = *min_element(sum, sum + 5);
    int mx = *max_element(sum, sum + 5);

    return mx - mn;

}

int main() {
    fastIO;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) cin >> arr[i][j];
    }

    int ans = 0x7f7f7f7f;
    
    for (int x = 1;x <= n;x++) {
        for (int y = 1;y <= n;y++) {
            for (int d1 = 1; x + d1 < n && 1 <= y-d1 && y-d1 < y; d1++) {
                for (int d2 = 1; x + d1 + d2<=n && y + d2 > y && y + d2 <= n;d2++)

                   ans = min(ans, getDiff(x, y, d1, d2));

            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
