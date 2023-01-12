#include<bits/stdc++.h>
using namespace std;
int l, c;
char arr[20];
int used[20]; //18번째 인덱스에는 모음의 사용갯수 저장.
int ans[20];
bool isVol(char c) {
	if (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u')return true;
	else return false;
}
 //k는 현재 ans에 채워진 알파벳 인덱스의 수
void func(int k) {
	//base condition k가 주어진값 l과 같을때,
	if (k == l) {
		//모음의 갯수가 1개 이상이고 자음의 갯수가 2개 이상일떄만 출력
		if (used[18] > 0 && k - used[18] > 1) {
			for (int i = 0; i < k; i++) {
				cout << arr[ans[i]];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = 0; i < c; i++) {
		if (k == 0) {
			used[i] = 1;
			if(isVol(arr[i])) used[18] += 1;
			ans[k] = i;
			func(k + 1);
			used[i] = 0;
			if (isVol(arr[i])) used[18] -= 1;
		}
		else if (arr[ans[k - 1]] < arr[i] && used[i] == 0) {
			used[i] = 1;
			if (isVol(arr[i])) used[18] += 1;
			ans[k] = i;
			func(k + 1);
			used[i] = 0;
			if (isVol(arr[i])) used[18] -= 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	
	cin >> l >> c;
	
	for (int i = 0; i < c; i++) cin >> arr[i];
	sort(arr, arr + c, less<>());
	func(0);
}
