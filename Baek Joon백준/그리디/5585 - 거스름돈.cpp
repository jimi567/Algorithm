#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define X first
#define Y second
#define ll long long
int coin[6] = { 500,100,50,10,5,1 };
int n;

int main(void) {
    fastIO;
    cin >> n;
    int cost = 1000 - n;
    int ans = 0;
    int i = 0;
    while (cost) {
        if (coin[i] > cost) i++;
        else {
            cost -= coin[i];
            ans++;
        }
    }
    cout << ans;
}

