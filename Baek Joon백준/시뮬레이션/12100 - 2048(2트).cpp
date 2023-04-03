#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n;
int arr[22][22];//오리지널
int tmp[22][22];
int ans = 0;
void rotate() {//90도 회전
    int tmp2[22][22] = { 0, };
    for(int i=0;i<n;i++)
        for (int j = 0;j < n;j++) {
            tmp2[i][j] = tmp[n-1-j][i];
        }
    memcpy(tmp, tmp2, sizeof(tmp));
}
void go(int dir) {
    //회전시키기
    for(int i=0;i<dir;i++) rotate();

    for (int i = 0;i < n;i++) {
        //<이미 합쳐진것인지 아닌지,숫자>
        stack<pair<bool, int>> st;
        for (int j = n-1;j >=0;j--) {
            if (tmp[i][j] == 0) continue;
            //1, 스택이 안비어져있다.
            //2. 스택의 top이 합쳐지지 않은 숫자다
            //3. 해당수가 동일한 수이다.
            if (!st.empty() && !st.top().X && tmp[i][j] == st.top().Y) {
                int tmpn = st.top().Y + tmp[i][j];
                st.pop();
                st.push({ 1,tmpn });
            }
            else st.push({ 0,tmp[i][j] });
        }
        //새로운값으로 tmp 갱신
        fill(tmp[i], tmp[i] + n, 0);
        int idx = n-st.size();
        while (!st.empty()) {
            tmp[i][idx++] = st.top().Y; st.pop();
        }
       
    }
    //회전시켜놓은거 돌려놓기
    for (int i = 0;i <4- dir;i++) rotate();
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) cin >> arr[i][j];

    for (int c = 0;c < (1 << 10);c++) {
        int brute = c;
        memcpy(tmp, arr, sizeof(tmp));
        for (int i = 0;i < 5;i++) {
            int dir = brute % 4;
            brute /= 4;
            go(dir);
        }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                ans = max(ans, tmp[i][j]);
    }
    cout << ans;
}
    
