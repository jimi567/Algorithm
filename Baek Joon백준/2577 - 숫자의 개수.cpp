#include <bits/stdc++.h>
using namespace std;
// 내가 푼 방식으로 to_string , mem[s_mul[i] - '0']++; 등으로 형변환을 사용해서 풀었음
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int a, b, c = 0;
	cin >> a >> b >> c;
	
	int mem[10] = { 0, };
	int mul = a * b * c;
	string s_mul = to_string(mul);
	for (int i = 0; i < s_mul.size(); i++) mem[s_mul[i] - '0']++;
	
	for (int i = 0; i < 10; i++) cout << mem[i] << endl;
}

//몫 나머지를 황용한 방법
int main(int argc, const char *argv[]) {
 
	/*
	  0으로 초기화를 해야한다. 
	  아니면 garbage value, 즉 쓰레기 값이 들어있게 된다.
	  이 때 0으로 초기화 하는 방법은 {} 괄호만 쳐주거나,
	  {0,}, {0} 방식이 있다.
	 */
	int count[10] = {};
	int a, b, c;
 
	cin >> a >> b >> c;
 
	int res = a * b * c;
 
 
	// 곱한 값이 0이 될 때 까지 반복
	while(res != 0) {
		count[res % 10]++;	// res에서 나머지 10을 통해 자릿수를 얻어 인덱스로 활용
		res /= 10;			//  매 회 자릿수를 줄이기 위해 10을 나눈다.
	}
 
	// 0 부터 9까지 count 배열을 출력한다. (foreach문 사용)
	for (int v : count) {
		cout << v << "\n";
	}
	return 0;
}
 
