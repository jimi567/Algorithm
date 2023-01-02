#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string str;
	while (1) {
		getline(cin, str); //공백을 포함해서 입력을 받는 입력 함수 개행은 구분자로 문자열을 입력받음
		stack<char> st;
		string ans = "yes";
		if (str.length() == 1 and str[0] == '.') break;

		for (char c : str) {
			if (c == '(' or c == '[')  st.push(c);

			else if (c == ')') {
				if (!st.empty() and st.top() == '(') st.pop();

				else ans = "no";
			}
			else if (c == ']') {
				if (!st.empty() and st.top() == '[') st.pop();
				else ans = "no";
			}
			else continue;
		}

		if (!st.empty()) ans = "no";//괄호가 스택에 남아있는 경우

		cout << ans << '\n';
	}
	
}
