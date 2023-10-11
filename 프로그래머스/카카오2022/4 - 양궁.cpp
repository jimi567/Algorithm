#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11,0);
    int mx = 0;
    vector<int> tmp(11,0);
    
    for(int sub=0;sub < (1<<10);sub++){
        int cnt = 0;
        int r = 0;
        int a = 0;
        fill(tmp.begin(),tmp.end(),0);
        for(int i=0;i<10;i++){
            if(sub &(1<<i)){
                tmp[i] = info[i] + 1;
                cnt += tmp[i];
                r += 10-i;
            }
            else if(info[i] > 0 ){
                a += 10-i;
            }
        }
        
        if(cnt > n || r - a <= 0) continue;
        tmp[10] = n - cnt;
        if(mx < r-a){
            answer = tmp;
            mx = r-a;
        }
        else if(mx == r-a){
            for(int i=9;i>=0;i--){
                if(answer[i] > tmp[i]) break;
                else if(answer[i] == tmp[i]) continue;
                answer = tmp;
            }
        }
    }
    if (!mx) answer = vector<int>(1,-1);
    
    return answer;
}
