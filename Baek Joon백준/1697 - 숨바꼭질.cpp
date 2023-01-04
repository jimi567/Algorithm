#include <bits/stdc++.h>
using namespace std;
int arr[100001]; // 수빈이가 해당 인덱스에 이동하는 최단 시간 기록

int main(void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	
	queue<int> q;
	q.push(n);
	arr[n] = 1; //첫 시작지점 1로 지정 나중에 답출력할떈 -1해줘야됨

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next : {cur + 1, cur - 1, cur * 2}){
			if (next < 0 || next > 100000) continue;
			if (arr[next]) continue;
			arr[next] = arr[cur] + 1;
			q.push(next);
		}
	}
	cout << arr[k] - 1;
	
}
