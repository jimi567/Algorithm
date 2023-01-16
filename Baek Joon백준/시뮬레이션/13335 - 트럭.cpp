#include <bits/stdc++.h>
using namespace std;

int n, w, l;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w >> l;

    queue<int> truck;
    vector<pair<int,int>> onBr;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        truck.push(tmp);
    }
    int ans = 1;
    int curL = 0;
    while (!truck.empty() || !onBr.empty()) {
        if (truck.size() > 0) {
            if (curL + truck.front() <= l) {
                curL += truck.front();
                onBr.push_back({ truck.front(),w });
                truck.pop();
            }
        }
        for (int i = 0; i < onBr.size(); i++) { 
            onBr[i].second -= 1; 
        }
        if (onBr.front().second == 0) {
            curL -= onBr.front().first;
            onBr.erase(onBr.begin());
        }
        ans++;
    }
    
    cout << ans;
    
}
