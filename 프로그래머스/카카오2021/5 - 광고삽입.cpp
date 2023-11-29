#include <bits/stdc++.h>

using namespace std;

int arr[360000];
int conv(string str){
    stringstream ss(str);
    int h,m,s;
    char tmp;
    ss >> h >> tmp >> m >>tmp>> s;
    return h * 3600 + m *60 + s;
}
string toStr(int time){
    string answer = "";
    string ansH = to_string(time/3600);
    string ansM = to_string(time/60 % 60);
    string ansS = to_string(time%60);
    if(ansH.length() == 1) answer += "0" + ansH +":";
    else answer += ansH +":";
    if(ansM.length() == 1) answer += "0" + ansM +":";
    else answer += ansM +":";
    if(ansS.length() == 1) answer += "0" + ansS;
    else answer += ansS;
    return answer;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    int totalTime = conv(play_time);
    int ad = conv(adv_time);
   
    for(string log : logs){
        string s = log.substr(0,8);
        string e = log.substr(9,8);
        int st = conv(s);
        int en = conv(e);
        //cout << s << "=" <<st << " " << e << "=" <<en << endl;
        for(int i = st ;i<en;i++) arr[i]++;
    }
    
    long long curSum = 0;
    for(int i=0;i<ad;i++) curSum += arr[i];
    int mxPos = 0;
    long long mxSum = curSum;
    for(int i=1;i<=totalTime-ad;i++){
        curSum -= arr[i-1];
        curSum += arr[i+ad-1];
        if(mxSum < curSum){
            mxSum = curSum;
            mxPos = i;
        }
    }
    return toStr(mxPos);
}
