#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int loop;
	cin >> loop;
	

	while (loop--) {
		string str;
		cin >> str;
		string ans = "NO";
		stack<char> st;
		for (auto c : str) {
			if (st.empty()) st.push(c);
			else {
				if (c == ')' and st.top() == '(') st.pop();
				else st.push(c);
			}
		}
		if (st.empty()) ans = "YES";
		cout << ans << '\n';
	}
}
