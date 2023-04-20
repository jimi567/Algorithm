#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define X first
#define Y second
#define ll long long
int n, m;
int arr[10];
int used[10001];
unordered_map<string, bool> chk;
vector<int> num;

int ans;
void go() {
    if (num.size() == m) {
        string st;
        for (auto i : num) {
            st += to_string(i) + " ";
        }
        if (chk.find(st) != chk.end()) return;
        cout << st << '\n';
        chk.insert({ st, true });
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        num.push_back(arr[i]);
        used[i] = 1;
        go();
        num.pop_back();
        used[i] = 0;
    }
}
int main(void) {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    go();
}
