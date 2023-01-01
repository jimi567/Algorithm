#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int size;
	cin >> size;
	string ans = "";
	int arr[size];
	for (int i = 0; i < size; i++) cin >> arr[i]; //수열 넣어주기
	stack<int> st;
	int idx = 0; //arr의 현 인덱스
	string stack = ""; //st에서 만들어낸 수열

	for (int i = 1; i < size+1; i++) {
		if (!st.empty()) { //st.top() 런타임에러 방지
			while (st.top() == arr[idx]) { //스택의 top이 arr[idx]와 같으면 pop해줌
				stack += to_string(st.top());
				st.pop();
				ans += "-";
				idx++;
				if (st.empty()) break;
			}
		}
		st.push(i);
		ans += "+";
		
	}
	while (!st.empty()) { //st에 남은 숫자 전부 pop시켜서 stack문자열에 추가시켜줌 
		stack += to_string(st.top());
		st.pop();
		ans += '-';
	}
	string ArraySt = ""; //입력으로 받았던 수열
	for (int i : arr) ArraySt += to_string(i);


	if (stack != ArraySt) cout << "NO"; //st에서 만들어낸 수열이랑 원래 수열이랑 비교
	else {
		for (auto c : ans) cout << c << '\n'; //**** endl으로 바꾸면 시간초과가 난다..
												// '\n'으로 줄바꿈하자.. endl은 출력버퍼를 비워야해서 느리다고한다
	}
}
