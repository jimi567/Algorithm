#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n, k;

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;


int main(void) {
	fastIO;
	cin >> n;

	int in;
	cin >> in;
	pq1.push(in);
	cout << in << endl;
	for (int i = 1;i < n;i++) {
		cin >> in;
		if (pq1.size() == pq2.size()) {
			if (pq1.top() < in) pq2.push(in);
			else pq1.push(in);
		}
		else if (pq1.size() < pq2.size()) {
		  pq2.push(in);
			pq1.push(pq2.top());
			pq2.pop();
		}
		else {
			pq1.push(in);
			pq2.push(pq1.top());
			pq1.pop();
		}
		
		if (pq1.size() >= pq2.size()) cout << pq1.top() << endl;
		else cout << pq2.top() << endl;
	}

	
}
