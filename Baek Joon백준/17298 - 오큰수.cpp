#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	stack<pair<int,int>> st;//(인덱스,수열의 수)의 스택
	int num;
	cin>> num;
	st.push(make_pair(0,num)); //스택에 수열의 시작값 푸쉬
	int ans[n]; // 답이 저장되는 배열

	for (int i = 1; i < n; i++) {
		cin >> num; //새로운 수 입력받기

		while (st.top().second < num) { //새로운 수가 스택 상단의 수보다 크면  
			ans[st.top().first] = num; // ans[스택상단의 인덱스] = 오큰수 할당
			st.pop();
			if (st.empty()) break; //만약 스택이 비게되면 while문 탈출
		}
		st.push(make_pair(i,num)); //새로운 수랑 그 수의 인덱스값 스택에 푸쉬
	}
	while (!st.empty()) { //스택에  남아있는 값은 오큰수가없는 경우이므로 ans에 -1저장
		ans[st.top().first] = -1;
		st.pop();
	}

	for (int i : ans) cout << i << " "; //답 출력
}
