#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    int n = queue1.size();
    queue<int> q1;
    queue<int> q2;
    ll s1 = 0;
    ll s2 = 0;
    for(int i=0;i<n;i++){
        s1 += queue1[i];
        q1.push(queue1[i]);
        s2 += queue2[i];
        q2.push(queue2[i]);
    }
    int ret = 0;
    //3n번이면 최소 한번은 최초의 상태까지 돌아옴
    for(int i=0;i<3*n;i++){
        if(s1 == s2) break;
        else if(s1>s2){
            ll v = q1.front();q1.pop();
            s1 -= v;
            s2 += v;
            q2.push(v);
        }else{
            ll v = q2.front(); q2.pop();
            s1 += v;
            s2 -= v;
            q1.push(v);
        }
        ret++;
    }
    if(s1 == s2) return ret;
    return answer;
}
