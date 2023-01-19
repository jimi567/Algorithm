#include <bits/stdc++.h>
using namespace std;
#define S first
#define W second
vector<pair<int, int>> eggs;
int n;
int mx = 0;
int mem[10]; //계란의 내구도 기록

void go(int k) {
    if (n == k) {
        int curbrk = 0;
        for (int i = 0; i < n; i++) {
            if (mem[i] <= 0) curbrk++;
        }
        mx = max(mx, curbrk);
        return;
    }
    bool isEgg = false;
    for (int i = 0; i < n; i++) {
        if (i != k && mem[i] > 0) isEgg = true;
    }
    if (mem[k] > 0 && isEgg) {
        for (int i = 0; i < n; i++) {
            if (i != k && mem[i] > 0) {
                mem[i] -= eggs[k].W;
                mem[k] -= eggs[i].W;
                go(k + 1);
                mem[i] += eggs[k].W;
                mem[k] += eggs[i].W;
            }
        }
    }
    else {
        go(k + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        pair<int, int> tmp;
        cin >> tmp.S >> tmp.W;
        eggs.push_back(tmp);
        mem[i] = tmp.S;
    }

    go(0);
    cout << mx;
  
}
------------------------------------------------------------------------------------------------------------------------
// cnt를 전역변수로 선언해주고 재귀호출이 끝났을때 cnt를 빼주는 형식 76~80
// 현재 깰 수 있는  계란이 존재하는지 확인하는(isEgg) 과정 생략가능함 깰 수 있는 계란이 없으면 cnt가 n-1이니깐 (o(N) -> O(1))
  //  또 base condition에서도 반복문으로 깨져있는 계란을 확인안해도됨 (o(n) -> O(1)) --> 내꺼랑 비교해서 시간복잡도 절반 줄어들었음
#include <bits/stdc++.h>
using namespace std;
int n;
int s[10],w[10];
int mx = 0;
int cnt = 0; // 깨져있는 계란의 수

void solve(int a){ // a번째 계란으로 다른걸 깰 차례
  if(a == n){
    mx = max(mx,cnt);
    return;
  }
  if(s[a] <= 0 or cnt == n-1){
    solve(a+1);
    return;
  } // a번째 계란이 깨져있거나 다른 모든 계란이 깨져있으면 넘어감
  for(int t = 0; t < n; t++){ // t번째 계란을 내려치고 싶다
    if(t == a or s[t] <= 0) continue;
    s[a] -= w[t];
    s[t] -= w[a];
    if(s[a] <= 0) cnt++;
    if(s[t] <= 0) cnt++;
    solve(a+1);
    if(s[a] <= 0) cnt--;
    if(s[t] <= 0) cnt--;    
    s[a] += w[t];
    s[t] += w[a];
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s[i] >> w[i];
  }
  solve(0);
  cout << mx;  
}
