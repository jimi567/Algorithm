#include <bits/stdc++.h>
using namespace std;

unordered_map<char,int> maps;

string solution(vector<string> survey, vector<int> choices) {
    int n = survey.size();
    for(int i=0;i<n;i++){
        char c1 = survey[i][0];
        char c2 = survey[i][1]; 
        if(choices[i] < 4){
            maps[c1] += 4 - choices[i];
        }else if(choices[i] > 4){
            maps[c2] += choices[i] - 4;
        }
    }
    string answer = "";
    if(maps['R'] >= maps['T']) answer += 'R';
    else answer+='T';
    if(maps['C'] >= maps['F']) answer += 'C';
    else answer += 'F';
    if(maps['J'] >= maps['M']) answer += 'J';
    else answer += 'M';
    if(maps['A'] >= maps['N']) answer += 'A';
    else answer += 'N';
    return answer;
}
