#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int n, k;
int arr[205]; //내구도
bool pos[105];//로봇위치

void rotate() {
    int tmp[205] = { 0, };
    for (int i = 0;i < 2 * n;i++) {
        if (i == 2 * n - 1) tmp[0] = arr[i];
        else tmp[i + 1] = arr[i];
    }
    memcpy(arr, tmp, sizeof(arr));

    bool tmpPos[105] = { 0, };
    for (int i =0;i < n-2;i++) {
        tmpPos[i + 1] = pos[i];
    }
    tmpPos[n - 1] = false; //내리는위치는 무조건 false
    memcpy(pos, tmpPos, sizeof(pos));
}

void move() {
    for (int i = n - 2;i >= 0;i--) {
        if (pos[i] && !pos[i + 1] && arr[i + 1]) {
            arr[i + 1]--;
            pos[i] = false;
            pos[i + 1] = true;
        }
        if (i + 1 == n - 1) pos[i + 1] = false; //내리는 위치 무조건 false
    }
}
int main() {
    fastIO;
    cin >> n >> k;
    for (int i = 0;i < 2 * n;i++) cin >> arr[i];

    int ans = 0;
    while (1) {
        ans++;
        rotate();
        move();
        if (arr[0] && !pos[0]) { //로봇놓기
            pos[0] = true;
            arr[0]--;
        }
        int cnt = 0;
        for (int i = 0;i < 2 * n;i++) if(!arr[i]) cnt++;
        if (cnt >= k) break;
    }
    cout << ans;
    return 0;
}
