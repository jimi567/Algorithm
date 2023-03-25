#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tc, n,m;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
  

    while (tc--) {
        cin >> n >> m;
        if (m % 2) {
            if (!(n % 2)) cout << n / 2 << '\n';
            else cout << n / 2 + 1 << '\n';
        }
        else cout << n / 2 + 1<<'\n';
    }
}
    
