#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	deque<int> dq;
	int loop;
	cin >> loop;

	while (loop--) {
		string oper;
		cin >> oper;

		if (oper == "push_front") {
			int data;
			cin >> data;
			dq.push_front(data);
		}

		else if (oper == "push_back") {
			int data;
			cin >> data;
			dq.push_back(data);
		}
		
		else if (oper == "pop_front") {
			if (dq.size() == 0) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}

		else if (oper == "pop_back") {
			if (dq.size() == 0) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}

		else if (oper == "size") {
			cout << dq.size() << '\n';
		}

		else if (oper == "empty") {
			cout << dq.empty() << '\n';
		}

		else if (oper == "front") {
			if (dq.size() == 0) cout << -1 << '\n';
			else cout << dq.front() << '\n';
		}

		else if (oper == "back") {
			if (dq.size() == 0) cout << -1 << '\n';
			else cout << dq.back() << '\n';
		}
	}
}
