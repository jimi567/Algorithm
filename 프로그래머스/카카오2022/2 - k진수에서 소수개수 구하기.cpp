#include <bits/stdc++.h>
using namespace std;
#define ll long long
string convert(int n,int k){
    string ret = "";
    while(n/k){
        ret += to_string(n%k);
        n /= k;
    }
    ret += to_string(n);
    reverse(ret.begin(),ret.end());
    return ret;
}
bool isPrime(ll k){
    if(k<2) return 0;
    for(ll i=2;i<=sqrt(k);i++){
        if(k%i == 0) return 0;
    }
    return 1;
}
vector<ll> getNums(string s){
    vector<ll> ret;
    string tmp = "";
    for(char c : s){
        if(c != '0') tmp += c;
        else{
            if(tmp.empty()) continue;
            ret.push_back(stoll(tmp));
            tmp.clear();
        }
    } 
    if(!tmp.empty()) ret.push_back(stoll(tmp));
    return ret;
}
int solution(int n, int k) {
    int answer = 0;
    string conv = convert(n,k);
    vector<ll> nums = getNums(conv);
    
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
        if(isPrime(nums[i])) answer += 1;
    }
    return answer;
}
