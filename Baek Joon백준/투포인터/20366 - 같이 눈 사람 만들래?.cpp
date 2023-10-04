#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second


int n;
int h[666];

int getDiff(int a, int b, int c, int d) {
    return abs((h[a] + h[b]) - (h[c] + h[d]));
}

int main(void) {
    fastIO;
    
    cin >> n;
    for (int i = 0;i < n;i++) cin >> h[i];

    sort(h, h + n);
    int mn = 0x7f7f7f7f;
    for (int i = 0;i < n;i++) {
        for (int j = i + 1;j < n;j++) {
            int en = n - 1;
            int st = 0;
            while(st<en) {
                if (st == i || st == j) {
                    st++;
                    continue;
                }
                if (en == i || en == j) {
                    en--;
                    continue;
                }
                mn = min(mn, getDiff(i, j, st, en));
                int nst = st + 1;
                int nen = en - 1;
                while (nst == i || nst == j) nst++;
                while (nen == i || nen == j) nen--;
                if (getDiff(i, j, st, nen) < getDiff(i,j,nst,en)) en = nen;
                else st = nst;
            }
        }
    }
    cout << mn;
}
