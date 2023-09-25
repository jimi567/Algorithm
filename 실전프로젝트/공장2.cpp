#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second
int tc, n;
string oper;
string k;

char p;

int sum_a[25];
int sum_b[25];

int compare() {
    //같으면 0, A가 크면 양수 ,B가 크면 음수
    
    for (int i = 0;i < 25;i++) {
        if (sum_a[i] == sum_b[i]) continue;
        return sum_a[i] - sum_b[i];
    }
    return 0;
}
void sum(char key, string v) {
    reverse(v.begin(), v.end());
    if (key == 'A') {
        for (int i =0;i < v.size();i++) {
            int tmp = v[i] - '0';
            sum_a[24 - i] += tmp;
            
        }
        for (int i = 24;i > 0;i--) {
            sum_a[i - 1] += sum_a[i] / 10;
            sum_a[i] %= 10;
        }
    }
    else {
        for (int i = v.size() - 1;i >= 0;i--) {
            int tmp = v[i] - '0';
            sum_b[24-i] += tmp;
        }
        for (int i = 24;i > 0;i--) {
            sum_b[i - 1] += sum_b[i] / 10;
            sum_b[i] %= 10;
        }
    }
}

void sub(char key, string v) {
    reverse(v.begin(), v.end());
    if (key == 'A') {
        for (int i = v.size() - 1;i >= 0;i--) {
            int tmp = v[i] - '0';
            sum_a[24 - i] -= tmp;
        }
        for (int i = 21;i > 0;i--) {
            if (sum_a[i] >= 0) continue;
            sum_a[i - 1] += sum_a[i] / 10 - 1;
            sum_a[i] += 10 * (abs(sum_a[i]/10) + 1);
        }
    }
    else {
        for (int i = v.size() - 1;i >= 0;i--) {
            int tmp = v[i] - '0';
            sum_b[24 - i] -= tmp;
        }
        for (int i = 24;i > 0;i--) {
            if (sum_b[i] >= 0) continue;
            sum_b[i - 1] += sum_b[i] / 10 - 1;
            sum_b[i] += 10 * (abs(sum_b[i]/10) + 1);
        }
    }
}
int main(void) {
    fastIO;
    cin >> tc;
    
    while (tc--) {
        cin >> n;
        queue<string> a;
        queue<string> b;
        fill(sum_a, sum_a + 25, 0);
        fill(sum_b, sum_b + 25, 0);

        for (int i = 0;i < n;i++) {
            cin >> oper;
            if (oper == "ORDER") {
                cin >> k >> p;
                if (p == 'C') {
                    if (compare() <= 0) {
                        a.push(k);
                        sum('A', k);
                    }
                    else {
                        b.push(k);
                        sum('B', k);
                    }
                }
                else if (p == 'A') {
                    a.push(k);
                    sum('A', k);
                }
                else {
                    b.push(k);
                    sum('B', k);
                }
            }
            else {
                cin >> p;
                if (p == 'A') {
                    if (a.empty()) continue;
                    sub('A', a.front());
                    a.pop();
                }
                else {
                    if (b.empty()) continue;
                    sub('B', b.front());
                    b.pop();
                }
            }
        }
        bool flag = 0;
        for (int i = 0;i < 25;i++) {
            if (!flag && sum_a[i] != 0) flag = 1;
            if (flag) cout << sum_a[i];
        }
        if (!flag) cout << 0;
        cout << " ";
        flag = 0;
        for (int i = 0;i < 25;i++) {
            if (!flag && sum_b[i] != 0) flag = 1;
            if (flag) cout << sum_b[i];
        }
        if (!flag) cout << 0;
        cout << endl;
    }
}
