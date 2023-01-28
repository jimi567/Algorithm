//테이블 d[i]는 i번쨰까지의 합
// d[i] = d[i-1] + 수열의 i번째 항
// d[endIndex] - d[startIndex - 1]를 구하면 구간합을 구할 수 있음
#include <bits/stdc++.h>
using namespace std;
int n,m;
int d[100001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> v;
    v.push_back(0); //1-indexed 맞추기
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    d[0] = 0;
    d[1] = v[0];
    for (int i = 2; i <= n; i++) d[i] = d[i - 1] + v[i];
    while (m--) {
        int si, ei;
        cin >> si >> ei;
        cout << d[ei] - d[si-1] << '\n';
    }

}
