#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, ' ')) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
  
    unordered_map<string,int> cnt_report;
    unordered_map<string, vector<string>> report_user;
    
    for(int i=0;i<id_list.size();i++){
        cnt_report.insert({id_list[i],0});
        report_user.insert({id_list[i],vector<string>()});
    }
    
    for(int i=0;i<report.size();i++){
        vector<string> info = split(report[i]);
        bool flag = 1;
        for(auto ur : report_user[info[0]]) if(ur == info[1]) flag =0;
        if(!flag) continue;
        report_user[info[0]].push_back(info[1]);
        cnt_report[info[1]] += 1;
    }
    for(int i=0;i<id_list.size();i++){
        int cnt = 0;
        for(auto user : report_user[id_list[i]]){
            if(cnt_report[user] >= k) cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
