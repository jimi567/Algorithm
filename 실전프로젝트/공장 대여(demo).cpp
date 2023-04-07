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

//v2 - 정답 코드 f를 gcd로 고정시키는게 아니라 f의 후보군중 gcd의 약수도 포함될 수 있음을 생각해야됨
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
vector<int> get_f(vector<int> v) {
    int tmp = 0;
    for (int i = 0;i < v.size() - 1;i++) {
        if (!tmp) tmp = gcd(v[i], v[i + 1]);
        else {
            tmp = gcd(tmp, v[i + 1]);
        }
    }
    vector<int> ret;
    for (int i = 1;i <= tmp;i++) if (tmp % i == 0) ret.push_back(i);
    return ret;
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
        vector<int> f = get_f(arg); //f의 후보군
        sort(info.begin(), info.end());
        vector<pair<int, int>> ct; //가능합 조합이 들어가는 벡터
        for (int i = 0;i < f.size();i++) {
            int point = 0;
            for (int j = 0;j < info.size();j++) {
                if (info[j].Y > f[i]) {
                    point = info[j].X;
                    break;
                }
            }
            for (int j = 1;j <= point;j++) {
                bool can = true;
                for (int k = 0;k < info.size();k++) {
                    int cost = ((info[k].X / j) + 1) * f[i];
                    if (cost == info[k].Y) continue;
                    can = false;
                    break;
                }
                if (can) ct.push_back({j,f[i]});
            }
        }
           //int overflow 항상 생각하자
        ll mn = 0x10f10f10f10f;
        ll mx = 0;
        for (int i = 0;i < ct.size();i++) {
            mx = max(mx, (ll)(t / ct[i].X + 1) * ct[i].Y);
            mn = min(mn, (ll)(t / ct[i].X + 1) * ct[i].Y);
        }
        if (!ct.size()) cout << -1 << '\n';
        else cout << mn << " " << mx << '\n';

    }
}
