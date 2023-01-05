#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[10]; // 답이 저장되는 배열
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
            arr[k] = i;
            f(k + 1);

    }
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    f(0);
   

}
