#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int n : course){
        //cout << "-------------------" << endl;
        unordered_map<string,int> cnt;
        for(auto order : orders){
            if(n > order.size()) continue;
            vector<int> cb(order.size(),1);
            for(int i=0;i<order.size()-n;i++) cb[i] = 0;
            do{
                string conbi;
                for(int i=0;i<order.size();i++){
                    if(!cb[i]) continue;
                    conbi += order[i];
                }
                sort(conbi.begin(),conbi.end());
                cnt[conbi]++;
            }while(next_permutation(cb.begin(),cb.end()));
        }
        int mx = 1;
        for(auto iter : cnt){
            //cout << iter.first << " " << iter.second << endl;
            if(mx < iter.second){
                mx = iter.second;
            }
        }
        //cout << mx << endl;
        if(mx < 2) continue;
        for(auto iter : cnt){
            if(mx == iter.second){
                answer.push_back(iter.first);
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
