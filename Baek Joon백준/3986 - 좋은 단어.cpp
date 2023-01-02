#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int loop;
	cin >> loop;
	
	int ans = 0;
	while (loop--) {
		string str;
		cin >> str;

		stack<char> st;
		for (auto c : str) {
			if (st.empty()) st.push(c); //첫 알파벳이 들어올때
			else {
				if (st.top() == c) st.pop(); //스택의 top이 현재 c와 같으면 pop
				else st.push(c); //아니면 스택에 c를 푸쉬
			}
		}
		if (st.empty()) ans++; //만약 스택이 비어있으면 좋은단어
	}

	cout << ans << '\n';

}
