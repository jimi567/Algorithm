#include <bits/stdc++.h>
using namespace std;
int n;


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if(n==1){ //primes가 n에 맞게 생성되므로 2 미만인 수 1은 예외처리해줬음
    cout << 0 ;
    return 0;
  }
  vector<bool> state(n+1,true);

  for(int i=2;i*i<=n;i++){
    if(!state[i]) continue;
    for(int j=i*i;j<=n;j+=i) state[j] = false;
  }
  vector<int> primes;
  for(int i=2;i<=n;i++){
    if(state[i]) primes.push_back(i);
  }
  int cnt = 0;
  int en = 0;
  int sum = primes[0];

  for(int st=0;st<primes.size();st++){
    while(sum < n && en < primes.size()){
      en++;
      sum+=primes[en];
    }
    if(sum==n) {
      cnt++;
    }
    if(en>=primes.size()) break;
    sum -= primes[st];
  }
  cout << cnt;
}
