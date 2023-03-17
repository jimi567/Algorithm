#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc, n;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> tc;
    
    while (tc--) {
        cin >> n;
        stack<int> st;
        int ans = 0;
        for (int i = 0;i < n;i++) {
            int tmp;
            cin >> tmp;
            st.push(tmp);
        }
        int current_Max = 0;
        while (!st.empty()) {
            if (current_Max < st.top()) ans++;
            current_Max = max(current_Max, st.top());
            st.pop();
        }
        cout << ans << '\n';
    }
}
