#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	deque<int> dq;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) dq.push_back(i);

	int ans = 0;

	int m;
	cin >> m;
	while (m--) {
		int data;
		cin >> data;
		//데이터가 front에 올떄까지
		while (dq.front() != data) {
			if (dq.size() == 1) break;
			int idx; //현재 덱에서의 data가 존재하는 인덱스값
			//현재 data가 존재하는 인덱스 값 찾기
			for (int i = 0; i < dq.size(); i++) {
				if (dq[i] == data) idx = i;
			}
			//만약 덱의 데이터의 위치가 front에 가깝다면 2번 작업 만약 데이터의 위치가 딱 중앙이면 2번 작업을 하는게 최솟값임 왜냐하면 추출은 front에서 이루어지기 떄문에
			if (idx <= dq.size() / 2) {	
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
			//만약 덱의 데이터의 위치가 back에 가깝다면 3번 작업 
			else {
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
		}
		// 1번 작업 수행
		dq.pop_front();
		
	}
	cout << ans << '\n';

}
