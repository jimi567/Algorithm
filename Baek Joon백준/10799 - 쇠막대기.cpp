#include<bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false),cin.tie(0);

	stack<char> S;
	string input;
	int total = 0;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			S.push(input[i]);
		}
		else if (input[i] == ')' and input[i - 1] == '(') { // 레이저일때
			S.pop();
			total += S.size();
		}
		else { // 마지막 자투리일때
			total++;
			S.pop();
		}
	}
	cout << total << endl;
}
