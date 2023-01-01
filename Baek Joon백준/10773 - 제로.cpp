#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int loop;
	cin >> loop;
	int n;
	stack<int> st;
	int sum = 0;
	while (loop-- ) {
		cin >> n;
		if (n > 0) {
			st.push(n);
		}
		else {
			if (st.size() > 0) st.pop();
		}
	}
	while (st.size()) { //장부에 적힌 총 금액 구하기
		sum += st.top();
		st.pop();
	}
	
	cout << sum;


}
