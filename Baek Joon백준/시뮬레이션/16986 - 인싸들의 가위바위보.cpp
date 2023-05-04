#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n, k;
int rule[12][12];
//내는 순서
vector<int> seq[3];

int solution() {
	do {
		int cnt[3] = { 0,0,0 };
		//이전에 이긴 사람
		int v = 0;
		bool chk[3] = { 0,1,0 }; //이번 라운드 상대
		int mot[3] = { 0,0,0 }; //내는 순서
		for (int i = 0;i < 20 ;i++) {
			if (mot[0] >= n) break; //낼 수 있는 수를 다냈음
			int s; //이번 라운드 상대
			for (int j = 0;j < 3;j++) if (chk[j]) s = j;
			//다음라운드에 참가할 사람으로 셋팅
			fill(chk, chk + 3, 1);
			chk[v] = 0;
			chk[s] = 0;
			//a => v가 내는 모양
			//b => s가 내는 모양
			int a = seq[v][mot[v]];
			int b = seq[s][mot[s]];
			mot[v]++;
			mot[s]++;

			if (rule[a][b] == 1) {
				if (v > s) cnt[v]++;
				else {
					cnt[s]++;
					v = s;
				}
			}
			else if (rule[a][b]== 2) {
				cnt[v]++;
			}
			else {
				cnt[s]++;
				v = s;
			}

			if (cnt[0] == k)return 1;
			if (cnt[1] == k || cnt[2] == k) break;
		}
	} while (next_permutation(seq[0].begin(), seq[0].end()));
	return 0;
}


int main(void) {
	fastIO;
	
	cin >> n >> k;
	
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) cin >> rule[i][j];

	for (int i = 1;i <= n;i++) seq[0].push_back(i);

	for (int i = 1;i <= 2;i++)
		for (int j = 0;j < 20;j++) {
			int in;
			cin >> in;
			seq[i].push_back(in);
		}
	cout << solution();
	
}
