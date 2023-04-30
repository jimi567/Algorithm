#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n, k;
int arr[10];
bool used[10];
unordered_map<string, bool> dic;
vector<int> v;
void go() {
	if (v.size() == k) {
		string st = "";
		for (auto i : v) {
			st += to_string(i) + " ";;
		}
		if (dic.find(st) != dic.end()) return;
		dic.insert({ st,1 });
		cout << st;
		cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (v.size() != 0 && v.back() > arr[i]) continue;
		v.push_back(arr[i]);
		go();
		v.pop_back();
	}
}

int main(void) {
	fastIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	go();
}
