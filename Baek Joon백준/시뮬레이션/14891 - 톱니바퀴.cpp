#include <bits/stdc++.h>
using namespace std;
//톱니바퀴 1~4
string arr[4];
//회전 시키기
void rotate(int n, int dir) {
    //오른쪽으로 회전
    if (dir == 1) {
        string tmp;
        tmp += arr[n][7];
        for (int i = 0; i < 7; i++) {
            tmp += arr[n][i];
        }
        arr[n] = tmp;
    }
    //왼쪽으로 회전
    if(dir == -1){
        string tmp;
        for (int i = 1; i < 8; i++) {
            tmp += arr[n][i];
        }
        tmp += arr[n][0];
        arr[n] = tmp;
    }
}
//회전 전파 후 rotate함수 호출
void makeSpin(int n, int dir) {
    int dirs[4] = { 0, };
    dirs[n] = dir;
    //왼쪽 회전 전파
    int id = n;
    while (id > 0 && arr[id][6] != arr[id - 1][2]) {
        dirs[id - 1] = -1 * dirs[id];
        id--;
    }
    //오른쪽 회전 전파
    id = n;
    while (id < 3 && arr[id][2] != arr[id + 1][6]) {
        dirs[id + 1] = -1 * dirs[id];
        id++;
    }
    for (int i = 0; i < 4; i++) {
        rotate(i, dirs[i]);
    }
}
int calcAns() {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i][0] == '1') ans += 1 << i;
    }
    return ans;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;

    while (k--) {
        int n, dir; //톱니 번호 /방향
        cin >> n >> dir;
        makeSpin(n - 1 , dir);
    }
    cout << calcAns();
}
