#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	queue<int> q;
	int loop;
	cin >> loop;

	while (loop--) {
		string oper;
		cin >> oper;

		if (oper == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (oper == "pop") {
			if (q.size() == 0) cout << -1 << '\n';
			else { 
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (oper == "size") cout << q.size() << '\n';

		else if (oper == "empty") cout << q.empty() << '\n';

		else if (oper == "front") {
			if (q.size() == 0) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}

		else if (oper == "back") {
			if (q.size() == 0) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}
