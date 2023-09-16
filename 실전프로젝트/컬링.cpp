#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int tc;

double a[8];
double b[8];

int main() {
    fastIO;

    cin >> tc;
 
    while (tc--) {
    
        fill(a, a + 8, 9999);
        fill(b, b + 8, 9999);
        for (int i = 0;i < 16;i++) {
            int x, y;
            cin >> x >> y;
            double d = sqrt(x * x + y * y);
            if (d >= 10) continue;
            if (i % 2 == 0) a[i / 2] = d;
            else b[i / 2] = d;
        }
        
        double ma = *min_element(a, a + 8);
        double mb = *min_element(b, b + 8);
        
        int sc = 0;
        if (ma <= mb) {
            for (int i = 0;i < 8;i++) {
                if (a[i] < mb) sc++;
            }
            cout << sc << " " << 0 << endl;
        }
        else {
            for (int i = 0;i < 8;i++) {
                if (b[i] < ma) sc++;
            }
            cout << 0 << " " << sc << endl;
        }

    }
}
