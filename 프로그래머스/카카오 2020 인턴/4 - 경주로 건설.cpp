#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int arr[31][31];
int vis[31][31];
int pre[31][31];

int solution(vector<vector<int>> board) {
    int n = board.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = board[i][j];
        }
    }
    queue<tuple<int,int,int>> q;
    vis[0][0] = 1;
    q.push({0,0,0});
    cout << n << endl;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int state = get<2>(cur);
        int now = 0;
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            //cout << nx << " " << ny << endl;
            if( nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(arr[nx][ny]) continue;
            int cost = vis[x][y];
            cost += 100;
            if(nx != x) now = 0;
            else if(ny != y) now = 1;
            if(!((x == 0 && y == 0) || state == 2) && now != state) cost+=500;
            if(vis[nx][ny] != 0 && vis[nx][ny] < cost) continue;
            if(vis[nx][ny] == cost) now = 2;
            vis[nx][ny] = cost;
            q.push({nx,ny,now});

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << vis[i][j] << "  " ;
        }
        cout << endl;
    }
    return vis[n-1][n-1] - 1;
}
