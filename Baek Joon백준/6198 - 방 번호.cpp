#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string n;
	cin >> n;

	//방 번호 구성에 필요한 플라스틱 숫자 갯수 구하기
	int arr[10] = { 0, }; 
	 
	for (int i= 0; i < n.size(); i++) { //a
			arr[n[i] - '0'] ++;
	}

	//6이랑 9는 뒤집어서 활용 가능하므로 6,9가 나오는 횟수 구함
	int cnt_6 = 0;
	int cnt_9 = 0;

	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '6')cnt_6++;
		else if (n[i] == '9') cnt_9++;
	}
	
	//6,9가 나오는 횟수의 차의 2로 나눈값을 arr에서 빼줌
	// 이 부분이 없으면 699는 1세트라는 답이 나옴.
	int c = abs(cnt_6 - cnt_9);
	arr[6] -= c / 2;
	arr[9] -= c / 2;

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		if (arr[i] > ans) ans = arr[i];
	}
	cout << ans;

}
