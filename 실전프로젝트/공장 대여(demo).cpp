#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc;
int n, t;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int get_f(vector<int> v) {
    int tmp = 0;
    for (int i = 0;i < v.size()-1;i++) {
        if (!tmp) tmp = gcd(v[i], v[i + 1]);
        else {
            tmp = gcd(tmp, v[i+1]);
        }
    }
    return tmp;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    
    while (tc--) {
        cin >> n >> t;
        vector<pair<int, int>> info;
        vector<int> arg;
        for (int i = 0;i < n;i++) {
            int time, price;
            cin >> time >> price;
            info.push_back({ time,price });
            arg.push_back(price);
        }
        int f = get_f(arg);
        sort(info.begin(), info.end());
        int point;
        for (int i = 0;i < info.size();i++) {
            if (info[i].Y > f) {
                point = info[i].X;
                break;
            }
        }
        vector<int> ct;
        for (int i = 1;i < point;i++) {
            bool can = true;
            for (int j = 0;j < info.size();j++) {
                int cost = (info[j].X / i + 1) * f;
                if (cost != info[j].Y) {
                    can = false;
                    break;
                }
            }
            if (can) ct.push_back(i);
        }
        int mn = 0x7f7f7f7f;
        int mx = 0;
        for (int i = 0;i < ct.size();i++) {
            mx = max(mx, (t / ct[i] + 1) * f);
            mn = min(mn, (t / ct[i] + 1) * f );
        }
        if (!ct.size()) cout << -1 << '\n';
        else cout << mn << " " << mx << '\n';
        
    }
}

//v2 - 시간 살짝? 개선
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int tc;
int n, t;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int get_f(vector<int> v) {
    int tmp = 0;
    for (int i = 0;i < v.size()-1;i++) {
        if (!tmp) tmp = gcd(v[i], v[i + 1]);
        else {
            tmp = gcd(tmp, v[i+1]);
        }
    }
    return tmp;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    
    while (tc--) {
        cin >> n >> t;
        vector<pair<int, int>> info;
        vector<int> arg;
        for (int i = 0;i < n;i++) {
            int time, price;
            cin >> time >> price;
            info.push_back({ time,price });
            arg.push_back(price);
        }
        int f = get_f(arg);
        sort(info.begin(), info.end());
        int point;
        for (int i = 0;i < info.size();i++) {
            if (info[i].Y > f) {
                point = info[i].X;
                break;
            }
        }
        int st = 1;
        for (int i = 1;i < point;i++) {
            bool can = true;
            for (int j = 0;j < info.size();j++) {
                int cost = (info[j].X / i + 1) * f;
                if (cost != info[j].Y) {
                    can = false;
                    break;
                }
            }
            if (can) {
                st = i;
                break;
            }
        }
        int en = st;
        for (int i = en; i < point;i++) {
            bool can = true;
            for (int j = 0;j < info.size();j++) {
                int cost = (info[j].X / i + 1) * f;
                if (cost != info[j].Y) {
                    can = false;
                    break;
                }
            }
            if (!can) {
                en = i - 1;
                break;
            }
        }

        int mn = 0x7f7f7f7f;
        int mx = 0;
        for (int i = st;i <= en;i++) {
            mx = max(mx, (t / i + 1) * f);
            mn = min(mn, (t / i + 1) * f );
        }
        if (mx == 0) cout << -1 << '\n';
        else cout << mn << " " << mx << '\n';
        
    }
}
