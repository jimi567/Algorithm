#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int tc, n;
string oper;
int k;
char p;
int sa, sb;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        cin >> n;
        queue<int> a;
        queue<int> b;
        sa = 0;
        sb = 0;
        for(int i=0;i<n;i++){
            cin >> oper;
            if (oper == "ORDER") {
                cin >> k >> p;
                if (p=='C') {
                    if (sa <= sb) {
                        a.push(k);
                        sa += k;
                    }
                    else {
                        b.push(k);
                        sb += k;
                    }
                }
                else if (p == 'A') {
                    a.push(k);
                    sa += k;
                }
                else {
                    b.push(k);
                    sb += k;
                }
            }
            else {
                cin >> p;
                if (p == 'A') {
                    int done = a.front(); a.pop();
                    sa -= done;
                }
                else {
                    int done = b.front(); b.pop();
                    sb -= done;
                }
            }
        }
        cout << sa << " " << sb << '\n';
    }
   
}
