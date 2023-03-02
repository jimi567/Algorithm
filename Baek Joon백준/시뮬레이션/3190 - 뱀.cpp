#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n, k,l;
int arr[105][105];
int dx[4] = { 0,1,0,-1 }; //서,남,동,북
int dy[4] = { 1,0,-1,0 };
char trans[10005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0;i < k;i++) {
        int x, y;
        cin >> x >> y;
        arr[x-1][y-1] = 2;
    }
    arr[0][0] = 1;
    cin >> l;
    for (int i = 0;i < l;i++) {
        int x;
        char c;
        cin >> x >> c;
        trans[x] = c;
    }

    int t = 0;
    int dir = 0; //뱀 초기는 오른쪽 바라보고있음
    list<pair<int, int>> path; // 뱀의 이동경로
    path.push_front({0,0});
    while (1) {
        t++;
        int hx = path.front().X + dx[dir];
        int hy = path.front().Y + dy[dir];
        //cout <<t << " : " <<  hx << " " << hy << endl;
        //벽에 머리박거나 자기자신의 몸과 부딪히면 끝
        if (hx < 0 || hy < 0 || hx >= n || hy >= n || arr[hx][hy] == 1) break;
        path.push_front({ hx,hy });
        //사과가 있다면
        if (arr[hx][hy] == 2) {
            arr[hx][hy] = 1;
        }
        //사과가 없다면
        else {
            arr[path.back().X][path.back().Y] = 0;
            path.pop_back();
            arr[hx][hy] = 1;
        }
        //방향정보 갱신
        if (trans[t] == 'L') dir = (dir + 3) % 4;
        if (trans[t] == 'D') dir = (dir + 1) % 4;
    }

    cout << t;


}
