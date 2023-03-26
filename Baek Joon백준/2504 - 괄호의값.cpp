#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
int n, m;
string str;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    stack<char> s;
    int ans = 0;
    int temp = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            temp *= 2;
            s.push('(');
        }
        else if (str[i] == '[') {
            temp *= 3;
            s.push('[');
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {   //올바르지 못한 괄호열
                ans = 0;
                break;
            }
            if (str[i - 1] == '(') {
                ans += temp;
                temp /= 2;
                s.pop();
            }
            else {
                temp /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {   //올바르지 못한 괄호열
                ans = 0;
                break;
            }
            if (str[i - 1] == '[') {
                ans += temp;
                temp /= 3;
                s.pop();
            }
            else {
                temp /= 3;
                s.pop();
            }
        }
    }

    if (!s.empty()) ans = 0;  //올바르지 못한 괄호열

    cout << ans;

    return 0;
}
