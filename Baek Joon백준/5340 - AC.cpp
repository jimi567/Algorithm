//내가 쓴 코드 이 문제 구현 자체가 많이 어렵다 다시 한번 풀어보자..
// reverse 함수의 시간초과로 인해 bool R 을 추가했다..
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int loop;
	cin >> loop;

	while (loop -- ) {
		bool isErr = false;
		string ans = "";
		string oper;
		cin >> oper;

		int n;
		cin >> n;
		deque<int> dq; //D연산이 처음 두수를 버리는 함수니깐 배열보단 front의 pop O(1)인 덱 채용

		string arr;
		cin >> arr;
		int i = 1;
		while (arr[i] != '\0') {
			int x = 0;
			while (arr[i] >= '0' and arr[i] <= '9') {
				x *= 10;
				x += int(arr[i] - '0');
				i++;
			}
			if (x != 0) {
				dq.push_back(x);
			}
			i++;
		}
		bool R = false;
		for (char c : oper) {
			if (c == 'R') {
				if (R) R = false;
				else R = true;
			}
			else if (c == 'D') {
				if (R) {
					if (dq.size() == 0)isErr = true;
					else {
						dq.pop_back();
					}
				}
				else {
					if (dq.size() == 0)isErr = true;
					else {
						dq.pop_front();
					}
				}
			}
		}
		if (isErr) ans = "error";
		else {
			if (!R) {
				ans += '[';
				for (int i = 0; i < dq.size();i++) {
					ans += to_string(dq[i]);
					if (i != dq.size()-1)ans += ',';
				}
				ans += ']';
			}
			else {
				ans += '[';
				for (int i = dq.size() -1; i >= 0; i--) {
					ans += to_string(dq[i]);
					if (i != 0)ans += ',';
				}
				ans += ']';
			}
		}

		cout << ans << '\n';
	}
}


