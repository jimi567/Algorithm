// ** 출력 포맷 잘보자.. <3, 4, 5> 이런식으로 출력해야되는데 그냥 3 4 5 이런식으로 값만 출력해서 계속틀렸다 
//내가 짠 코드 이중 연결 리스트를 활용해서품
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	list<int> circle;
	for (int i = 1; i <= n; i++)circle.push_back(i); //1~n까지의 숫자 넣어줌
	auto it = circle.begin();

	int idx = 1; // 순회할때 사용하는 idx
	cout << "<";
  
	while (circle.size() != 1) {
		if (idx % k == 0) { //idx가 k랑 나눠지면.. 해당 값을 서클에서 제외해야됨
			cout << *it << ", ";
			it = circle.erase(it);
			it--;
		}
		idx++;
		it++;
		if (it == circle.end()) { //iterator가 끝에 도달하면 처음으로 돌려줌
			it = circle.begin();
		}

	}
	cout << *it << ">" << endl;
	return 0;
}
// 다른 사람풀이 큐를 활용해 더 직관적으로 풀었음 맛있는 풀이 자료구조의 특징이랑 문제의 요구사항을 잘 연관지을필요성이있다.
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n,k,i;
	cin >> n;
	queue<int> s;
	for (int i=1; i<=n; i++) {		// 1~n의 숫자를 차례로 큐에 넣어줌
		s.push(i);
	}
	cout << "<";
	cin >> k;
	i = 1;
	while (n-1) {			// n-1이 0이 될 때까지 반복문 수행
		
		if (i % k != 0) {		// i 나누기 k의 나머지가 0이 아닐 때 front 값을 다시 큐에 넣고 pop
			s.push(s.front());
			s.pop();
		}
		else {				// i 나누기 k의 나머지가 0일 때 front 값을 출력하고 pop
			cout << s.front() << ", ";
			s.pop();
			n--;				// 빼는 시행마다 n을 1 제거
		}
		i++;			// 반복의 수만큼 i++;
	}
	cout << s.front() << ">";		// 마지막에 큐에 남은 값 출력
	return 0;
}
