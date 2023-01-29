// dp에서 이전 값의 경로를 모두 저장해주는 형식으로 짰음
// 메모리 소모도 심하고 각 수마다 모든 경로를 추가하니 시간도 오래걸림 통과하긴했으나 더 나은 방법이 있었음
#include <bits/stdc++.h>
using namespace std;
int n;
int d[1000001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    d[0] = 0;
    d[1] = 0;
    vector<vector<int>> seq;
    seq.push_back({ 0 });
    seq.push_back({ 1 });
    for (int i = 2; i <= n; i++) {
        vector<int> op = seq[i - 1];
        d[i] = d[i-1] + 1; //1을빼는 경우 
        if (i % 3 == 0 && d[i/3] + 1 < d[i]) { d[i] = d[i/3] + 1; op = seq[i / 3]; } //3으로 나누는 경우
        if (i % 2 == 0 && d[i/2] + 1 < d[i]) { d[i] = d[i/2] + 1; op = seq[i / 2]; }//2로 나누는 경우
        op.push_back(i);
        seq.push_back(op);
    }

   
    cout << d[n] << '\n';
    for (int i = seq[n].size() - 1; i >= 0; i--) cout << seq[n][i] << ' ';
}
-----------
// 지금 현재 값이 dp과정에서 어떤 값을 통해 왔는지를 저장하는 테이블을 추가로 만듦 -> pre테이블
// dp과정에서 pre테이블을 같이 채워나가고 나중에 출력해주면됨
  int n;
int pre[1000005], d[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;
		}
	}
	cout << d[n] << "\n";
	int cur = n;
	while (true)
	{
		cout << cur << " ";
		if (cur == 1)
			break;
		cur = pre[cur];
	}
}
