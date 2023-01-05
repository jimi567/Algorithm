#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10]; // 답이 저장되는 배열
int used[10]; // 해당 수를 사용했는지 안했는지 판별
void f(int k) { //k는 arr배열에 채워진 원소의 수
    if (k == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    //백트래킹
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            arr[k] = i;
            used[i] = 1;
            f(k + 1);
            used[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    f(0);
   

}
