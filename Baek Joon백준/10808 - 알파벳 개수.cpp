#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	for (char c = 'a'; c <= 'z'; c++) {
		int cnt = 0;
		for (char i : s) {
			if (i == c) cnt++;
	
		}
		cout << cnt << " ";
		cnt = 0;
	}
}