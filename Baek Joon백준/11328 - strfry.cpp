#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	int alpha[26] = { 0, };
	int alpha2[26] = { 0, };
	while (n--) {
		string str;
		string str2;
		cin >> str >> str2;
		string ans = "Possible";
		
		if (str.size() != str2.size()) ans = "Impossible";

		else {
			for (int i = 0; i < str.size(); i++) {
				alpha[str[i] - 'a']++;
				alpha2[str2[i] - 'a']++;
			}

			for (int i = 0; i < 26; i++) {
				if (alpha[i] != alpha2[i]) {
					ans = "Impossible";
					break;
				}
			}
		}
		cout << ans << '\n';
		fill(alpha, alpha + 26, 0);
		fill(alpha2, alpha2 + 26, 0);
	}
}
