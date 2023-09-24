#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define X first
#define Y second

int main(){
    fastIO;
    string s;

    int zero = 0, one = 0;

    cin >> s;

    if(s[0] == '0')

        zero++;

    else

        one++;

    for(int i = 1; i < s.size(); i++){

        if(s[i] != s[i-1]){

            if(s[i] == '0')

                zero++;

            else

                one++;

        }

    }

    cout << min(zero, one);

    return 0;

}
