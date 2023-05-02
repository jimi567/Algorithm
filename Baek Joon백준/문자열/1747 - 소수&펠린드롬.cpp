#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n;

bool isPrime(int num) {
	if (num == 1) return 0;
	for (int i = 2;i * i <= num;i++) {
		if (!(num % i)) return 0;
	}
	return 1;
}
bool isPalindrome(int num) {
	string ori = to_string(num);
	string tmp = "";
	for (int i = ori.size() - 1;i >= 0;i--) tmp += ori[i];
	
	return ori == tmp;
}

int main(void) {
	fastIO;
	cin >> n;

	while (1) {
		if (isPrime(n) && isPalindrome(n)) break;
		n++;
	}
	cout << n;
}
