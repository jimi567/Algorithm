#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc;
int n, m;
int arr[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        memset(arr, 0, sizeof(arr));
        for (int i = 0;i < n;i++) {
            cin >> arr[i];
        }
        ll a = 0;
        int k = 0;
        sort(arr, arr + n, greater<int>());
        vector<pair<int, int>> round;
        for (int i = 0;i < n;i += 2) {
            round.push_back({ arr[i],arr[i + 1] });
        }
        int idx = round.size();
        vector<pair<int,int>> diff;
        for (int i = 0;i < idx;i++) {
            diff.push_back({ round[i].X - round[i].Y,i });
        }
        sort(diff.begin(), diff.end(), greater<pair<int,int>>());
        vector<bool> use(idx, false);
        for (int i = 0;i < diff.size();i++) {
            if (k < m) {
                k++;
                use[diff[i].Y] = true;
            }
        }
        for (int i = 0;i < idx;i++) {
            if (use[i]) a += round[i].X;
            else a += round[i].Y;
        }
        cout << a << '\n';
    }
}
