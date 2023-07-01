#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define X first
#define Y second
int tc;
unordered_map<string, bool> work_at_home;
int team_mam_cnt[12];
vector<int> homeMan[12];
int main(void) {
	fastIO;
	cin >> tc;

	int team_cnt, work_home_cnt, work_comp_cnt, man_cnt;
	while (tc--) {
		cin >> team_cnt >> work_home_cnt >> work_comp_cnt >> man_cnt;

		for (int i = 0;i < 12;i++) homeMan[i].clear();
		memset(team_mam_cnt, 0, sizeof(team_mam_cnt));
		work_at_home.clear();

		for (int i = 0;i < work_home_cnt;i++) {
			string st;
			cin >> st;
			work_at_home.insert({ st,true });
		}
		for (int i = 0;i < work_comp_cnt;i++) {
			string st;
			cin >> st;
			work_at_home.insert({ st,false });
		}
		int team_num, m;
		for (int i = 1;i <= man_cnt;i++) {
			cin >> team_num >> m;
			bool can_home = true;
			for (int j = 0;j < m;j++) {
				string w;
				cin >> w;
				if (!work_at_home[w]) can_home = false;
			}
			if(can_home)homeMan[team_num].push_back(i);
			team_mam_cnt[team_num]++;
		}

		for (int i = 1;i <= team_cnt;i++){
			 sort(homeMan[i].begin(), homeMan[i].end(),greater<int>());
		}
		vector<int> ret;
		for (int i = 1;i <= team_cnt;i++) {
			if (team_mam_cnt[i] == homeMan[i].size()) homeMan[i].pop_back();
			for (int j = 0;j < homeMan[i].size();j++) ret.push_back(homeMan[i][j]);
		}
		sort(ret.begin(), ret.end());
		if (!ret.size()) cout << -1;
		else {
			for (int i = 0;i < ret.size();i++) cout << ret[i] << " ";
		}
		cout << '\n';
	}
}
