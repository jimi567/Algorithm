#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tc, n;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    string s;

    while (tc--) {
        stack<char> st;
        cin >> s;
        int ans = 0;
        st.push(s[0]);
        int l = 1;
        for (int i = 1; i < s.length();i++) {
            if (s[i] == ')') {
                if (st.top() == '(') {
                    ans += (l - 1);
                    l--;
                }
                else {
                    l--;
                    ans++;
                }
            }
            else l++;
            st.push(s[i]);
        }
        cout << ans<< '\n';
    }
}
