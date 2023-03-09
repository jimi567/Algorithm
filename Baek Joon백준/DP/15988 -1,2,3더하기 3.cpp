#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc, n;
const int mod = 1000000009;
ll d[1000005];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    d[1] = 1;
    d[2] = 2; //1+1 , 2
    d[3] = 4;  //1+1+1, 1+2, 2+1,3
    for (int i = 4;i <= 1000000;i++) {
        d[i] = (d[i - 1] + d[i - 2]  + d[i - 3]) % mod;
    }
    
    while (tc--) {
        cin >> n;
        cout << d[n] << '\n';
    }
   
}
