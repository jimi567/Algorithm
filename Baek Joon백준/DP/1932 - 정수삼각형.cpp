#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int tri[505][505]; //i번째 층/j번쨰 정수
int n;
int d[505][505]; //i번쨰 층 j번째 까지 도달했을때의 최댓값;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) cin >> tri[i][j];
    }

    d[0][0] = tri[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tri[i][j];
        }
    }
    //int mx = 0;
    //for (int i = 0; i < n; i++) {
    //    mx = max(mx, d[n - 1][i]);
    //}
    cout << *max_element(d[n - 1], d[n - 1] + n); //max_element(배열의 시작주소,끝주소) ==> 최댓값 주소반환
}
