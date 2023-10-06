#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc;
int n;
string arr[55][55];
//B: 행이 감소하는 방향, F : 행이 증가하는 방향,
//R : 열이 증가하는 방향, L : 열이 감소하는 방향
unordered_map<string, int> parse;
unordered_map<string, string> info;
bool rec[55][55][4]; //x,y 좌표에서 z방향 이동한적있나?
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void makeInfo() {
	info.insert({ "FF","F"});
	info.insert({ "FR","R"});
	info.insert({ "FL","L" });
	info.insert({ "FB","B"});
	info.insert({ "RF","R"});
	info.insert({ "RR","B" });
	info.insert({ "RL","F"});
	info.insert({ "RB","L" });
	info.insert({ "LF","L" });
	info.insert({ "LR","F" });
	info.insert({ "LL","B" });
	info.insert({ "LB","R" });
	info.insert({ "BF","B" });
	info.insert({ "BR","L" });
	info.insert({ "BL","R" });
	info.insert({ "BB","F" });

	parse.insert({ "F",0 });
	parse.insert({ "R",1 });
	parse.insert({ "B",2 });
	parse.insert({ "L",3 });
	
}
int main(void) {
	fastIO;
	cin >> tc;
	makeInfo();
	while (tc--) {
		memset(rec, false, sizeof(rec));
		cin >> n;
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) cin >> arr[i][j];
		}
		string prev = "B";
		int x = 0;
		int y = 0;
		while (1) {
			string next = info[prev + arr[x][y][0]];
			int mul = arr[x][y][1] - '0';
			if (rec[x][y][parse[next]]) break;
			rec[x][y][parse[next]] = true;
			prev = next;
			x += dx[parse[next]] * mul;
			y += dy[parse[next]] * mul;
		}
		cout << x << " " << y << endl;
	}
}
//2트
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int tc;
//f r b l
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n;
string arr[55][55];
bool chk[55][55][4];

int parseDir(char c) {
    if (c == 'F') return 0;
    if (c == 'R') return 1;
    if (c == 'B') return 2;
    return 3;
}
int main(void) {
    fastIO;
    
   
    cin >> tc;
    while (tc--) {

        cin >> n;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++) cin >> arr[i][j];

        memset(chk, false, sizeof(chk));

;       int dir = 2;
        
        pair<int, int> cur = { 0,0 };
        while (!chk[cur.X][cur.Y][dir]) {
            chk[cur.X][cur.Y][dir] = 1;
            dir += parseDir(arr[cur.X][cur.Y][0]);
            dir %= 4;
            int d = arr[cur.X][cur.Y][1] - '0';
            
            int nx = cur.X + dx[dir] * d;
            int ny = cur.Y + dy[dir] * d;
            cur = { nx,ny };
            
        }

        cout << cur.X << " " << cur.Y << endl;
    }
    
    
}
