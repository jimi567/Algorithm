#include<bits/stdc++.h>
using namespace std;
//동 남 서 북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
int arr1[10][10];//원본배열
int arr2[10][10];//복사본
vector<pair<int, int>> cctv; //cctv의 좌표를 담을 벡터
//cctv가 체크하는 함수
void chk(int x, int y, int dir) {
	dir %= 4; //입력으로 들어온 dir이 4보다 클 수 있으니깐 다시 4의 나머지로 할당
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m || arr2[x][y] == 6) return; //벽을 만났거나 범위를 벗어나면 cont
		if (arr2[x][y] == 0)//cctv가 비출수있는 빈칸이면 -1
			arr2[x][y] = -1;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;

	int ans = 0; //0의 갯수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j];
			if (arr1[i][j] > 0 && arr1[i][j] < 6)cctv.push_back({ i,j });
			if (arr1[i][j] == 0) ans++;
		}
	}
	//right shift 2의 지수승구할때 씀 -->  n << k --> n * (2**k)
	// 1 * 4**cctv.size()
	//각 cctv가 비추는 경우의 수를 4진법으로 표현 cctv가 4개면 256가지 방법을 다 체크
	for (int k = 0; k < (1 << (2 * cctv.size())); k++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr2[i][j] = arr1[i][j]; //arr2를 다시 초기화
		int brute = k;
		for (int i = 0; i < cctv.size(); i++) {
			int dir = brute % 4; //4진수의 각각의 자릿수의 값 뽑아냄 --> 각 cctv의 경우의 수
			brute /= 4;
			int x = cctv[i].first;
			int y = cctv[i].second;
			//dx dy는 동남서북 순
			//n번 cctv일때
			if (arr1[x][y] == 1) {
				chk(x, y, dir);
			}
			else if (arr1[x][y] == 2) {
				chk(x, y, dir);
				chk(x, y, dir + 2);
			}
			else if (arr1[x][y] == 3) {
				chk(x, y, dir);
				chk(x, y, dir + 3);
			}
			else if (arr1[x][y] == 4) {
				chk(x, y, dir);
				chk(x, y, dir + 2);
				chk(x, y, dir + 3);
			}
			else if (arr1[x][y] == 5) {
				chk(x, y, dir);
				chk(x, y, dir + 1);
				chk(x, y, dir + 2);
				chk(x, y, dir + 3);
			}
		}
		//현재 방법에 대한 사각지대의 갯수
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr2[i][j] == 0)
					cnt++;
		ans = min(ans, cnt);
	}
	cout << ans;
}
