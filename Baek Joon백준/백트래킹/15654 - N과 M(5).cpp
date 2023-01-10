//내가 푼거 used에 숫자자체에 사용여부를 남겼음
#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[10];
bool used[10001];
int nums[10];
void func(int len){
	if (m == len) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!used[nums[i]]) {
			used[nums[i]] = 1;
			arr[len] = nums[i];
			func(len + 1);
			used[nums[i]] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> nums[i];
	sort(nums, nums + n);
	func(0);
}
//used에 숫자말고 그 주어진 수열의 인덱스로 사용여부를 남겼음
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];
int num[10];

void func(int k){ // 현재 k개까지 수를 택했음.
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << num[arr[i]] << ' '; // arr에 기록해둔 인덱스에 대응되는 수를 출력
    cout << '\n';
    return;
  }

  for(int i = 0; i < n; i++){ // 0부터 n-1까지의 인덱스에 대해
    if(!isused[i]){ // 아직 i가 사용되지 않았으면
      arr[k] = i; // k번째 인덱스를 i로 정함
      isused[i] = 1; // i를 사용되었다고 표시
      func(k+1); // 다음 인덱스를 정하러 한 단계 더 들어감
      isused[i] = 0; // k번째 인덱스를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> num[i];
  sort(num, num+n); // 수 정렬
  func(0);
}
//STL next_permutation을 이용해 n개에서 m개를 뽑음, 그 뽑은 수들 중에서 수열을 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
int arr[10];
vector<int> save(10);
vector<vector<int>> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++)
        cin >> save[i];
    sort(save.begin(), save.begin()+N);
    fill(arr, arr+N, 1);
    for(int i=0;i<M;i++) arr[i] = 0;    

    do{
        /* 1) 조합으로 뽑은 숫자를 tmp에 저장
           2) tmp에 대해 next_permutation() 수행 */
        vector<int> tmp;
        for(int i=0;i<N;i++)
            if(!arr[i]) tmp.push_back(save[i]);
        do{
            ans.push_back(tmp);
        }while(next_permutation(tmp.begin(), tmp.end()));
    }while(next_permutation(arr, arr+N));

    /* 제일 앞 요소가 작은 순서대로 오름차순 정렬 */
    sort(ans.begin(), ans.end());
    /* 2중 for문으로 출력 */
    for(auto a : ans)
    {
        for(auto b : a)
            cout << b << ' ';
        cout << '\n';
    }
    return 0;
}
