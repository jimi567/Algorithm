#include <string>
#include <vector>
#include<iostream>

using namespace std;
bool isNum(char c){
    return c >= '0' && c <= '9';
}
string solution(string new_id) {
    string answer = new_id;
    string tmp = "";
    for(int i=0;i<answer.size();i++){
        if(isupper(answer[i])) tmp += tolower(answer[i]);
        else tmp += answer[i];
    }
    answer = tmp;
    tmp = "";
    for(int i=0;i<answer.size();i++){
        if(isalpha(answer[i]) || answer[i] == '-' || answer[i] == '_' || answer[i] == '.' || isNum(answer[i])) tmp += answer[i];
        }
    answer = tmp;
    tmp = "";
    for(int i=0;i<answer.size() - 1;i++){
        if(answer[i] =='.' && answer[i+1] =='.')continue;
        tmp += answer[i];
    }
    tmp += answer[answer.size()-1];
    answer = tmp;
    if(answer[0] == '.') answer = answer.substr(1,answer.size());
    if(answer[answer.size()-1] == '.') answer = answer.substr(0,answer.size()-1);
    
    if(answer == "") answer = "a";
    if(answer.size() >= 16) {
        answer = answer.substr(0,15);
         if(answer[answer.size()-1] == '.') answer = answer.substr(0,answer.size()-1);
    }
    if(answer.size() <= 2) {
        while(answer.size() < 3) answer+=answer[answer.size()-1];
    }
    return answer;
}
