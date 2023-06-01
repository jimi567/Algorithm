#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc;
int n;
int main() {
    fastIO;
    vector<bool> isPrime(270000, true);
    for (int i = 2;i * i <= 270000;i++) {
        if (!isPrime[i]) continue;
        bool isPrimeNum = true;
        for (int j = 2; j<i;j++) {
            if (i % j == 0) isPrimeNum = false;
        }
        if (isPrimeNum) {
            for (int j = 2;j * i <= 270000;j++) isPrime[i * j] = 0;
        }
    }
    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> init;
        for (int i = 1;i <= n;i++) init.push_back(i);
        queue <vector<int>> calc;
        queue<vector<int>> ret;

        calc.push(init);
        while (!calc.empty()) {
            auto cur = calc.front(); calc.pop();
            if (isPrime[cur.size()]){
                ret.push(cur);
                continue;
            }
            vector<vector<int>> tmp;
            for (int i = 2;i <= cur.size();i++) {
                if (isPrime[i] && cur.size() % i == 0) {
                    int p = cur.size() / i;
                    for (int j = 0;j < i;j++) {
                        vector<int> arg;
                        for (int k = 0;k < p;k++) {
                            arg.push_back(cur[j + k * i]);
                        }
                        tmp.push_back(arg);
                    }
                    break;
                }
            }
            for (auto t : tmp) calc.push(t);
        }

        while (!ret.empty()) {
            auto cur = ret.front(); ret.pop();
            for (auto num : cur) cout << num << " ";
        }
        cout << endl;
    }
}
