#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define X first
#define Y second
#define ll long long
int n, m;
int arr[10];
vector<int> num;

int ans;
void go() {
    if (num.size() == m) {
        for (auto i : num) cout << i << " ";
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (num.size() > 0 && arr[i] < num.back()) continue;
        num.push_back(arr[i]);
        go();
        num.pop_back();
    }

}

int main(void) {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    go();
}

