#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int arr[2][505][505]; //일반맵,대칭맵
int dx[5][4] = { {0,0,0,0}, //파랑
                {0,0,1,1},  //노랑
                {0,0,0,1},  //보라
                {0,1,2,2},  //주황
                {0,1,1,2}  // 초록
};
int dy[5][4] = { {0,1,2,3},
                {0,1,0,1},
                {0,1,2,1},
                {0,0,0,1},
                {0,0,1,1}
};
int n, m;
int ans;
bool OOB(int x, int y) {
    return x < 0 || y < 0 || x >= n || y >= m;
}
int getSum(int d,int type, int sx, int sy) {
    int sum = 0;
    for (int dir = 0; dir < 4;dir++) {
        int nx = sx + dx[type][dir];
        int ny = sy + dy[type][dir];
        if (OOB(nx, ny)) return -1;
        sum += arr[d][nx][ny];
    }
    return sum;
}

void rotatePaper(int d,int r) {
    int tmp[505][505];
    while(r--) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                tmp[j][n-1-i] = arr[d][i][j];
            }
        }
        memcpy(arr[d], tmp, sizeof(arr[d]));
        swap(n, m);
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++) cin >> arr[0][i][j];

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            arr[1][i][j] = arr[0][i][m-1-j];
        }
    }
    for (int d = 0;d < 2;d++) {//대칭값
        for (int r = 0;r < 4;r++) { //회전 0,90,270,180도 순으로 확인함
            rotatePaper(d,r);
            for (int k = 0;k < 5;k++) { //테트로미노 타입
                if (d == 1 && k < 3) continue;
                for (int i = 0;i < n;i++) { //좌표
                    for (int j = 0;j < m;j++) { //좌표
                        ans = max(ans, getSum(d, k, i, j));
                    }
                }
            }
        }
    }
    cout << ans;
}
