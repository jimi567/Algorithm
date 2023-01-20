using namespace std;
#define X first
#define Y second
string arr[12];
bool vis[105][105];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool flag = 1;//연쇄 발생했는가?
int cnt = 0; //연쇄횟수
vector<pair<int, int>> pang; //터트릴 뿌요뿌요 좌표
void reset() { //방문표시, pang 초기화
    for (int i = 0; i < 12; i++) {
        fill(vis[i], vis[i] + 6, 0);
    }
    pang.clear();
}
void rmc() { //뿌요뿌요터트리기;
    for (int i = 0; i < pang.size(); i++) {
        arr[pang[i].X][pang[i].Y] = '.';
    }
}
void remakeMap() { //맵 갱신
    for (int i = 11; i >= 0; i--) {
        for (int j = 5; j >= 0; j--) {
            if (arr[i][j] != '.' && i + 1 < 12 && arr[i+1][j] == '.') {
                int nx = i;
                while (nx + 1 < 12 && arr[nx + 1][j] == '.') nx++;
                arr[nx][j] = arr[i][j];
                arr[i][j] = '.';
            }
        }
    }
}
void printMap() {
    cout << endl;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 12; i++) cin >> arr[i];
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp; //bfs하면서 임시로 담아둘 좌표값들 tmp크기가 4이상이면 pang에 담을 예정
    while (flag) {
        flag = 0; 
        reset();
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (arr[i][j] != '.' && vis[i][j] == 0) {
                    tmp.push_back({ i,j });
                    q.push({ i,j });
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)continue;
                            if (arr[cur.X][cur.Y] != arr[nx][ny] || vis[nx][ny] == 1) continue;
                            tmp.push_back({ nx, ny });
                            q.push({ nx,ny }); vis[nx][ny] = 1;
                        }
                    }
                    if (tmp.size() > 3) {
                        flag = 1;//연쇄 발생
                        for (auto i : tmp) pang.push_back(i);
                    }
                    tmp.clear();
                }
            }
        }
        if (flag) {
            rmc();
            remakeMap();
            cnt++;
        }
    }
    cout << cnt;
}
