#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int loop;
	string s;
	list<char> pw;
	auto cur = pw.begin();

	cin >> loop;

	while (loop--) {
		// 입력받기
		cin >> s;
		//비밀번호 도출
		pw.clear();
		auto cur = pw.begin();
		for(auto c : s){
			if (c == '-') {
				if (cur != pw.begin()) cur = pw.erase(--cur); // erase 함수를 호출하면 무조건 iterator에 지운 다음 주소를 할당해줘야됨
															// 이것때문에 다 푼 문제 1시간 고민했음 출력초과나서...
			}
			else if (c == '<') {
				if (cur != pw.begin())cur--;
			}
			else if (c == '>') {
				if (cur != pw.end())cur++;
			}
			else pw.insert(cur, c);
		}
		for (auto c : pw)cout << c;
		cout << endl;
	}
	return 0;
}
