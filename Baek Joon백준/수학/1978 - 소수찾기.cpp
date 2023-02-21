#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n;
int ans;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (isPrime(num)) ans++;
    }
    cout << ans;
}
