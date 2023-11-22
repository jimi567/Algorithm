#include <bits/stdc++.h>
using namespace std;
int d[155][155];

int solution(int alp, int cop, vector<vector<int>> problems) {
    //왜 목표 초기를 0으로하면 틀리고 alp, cop로 하면 맞을까?
    int alp_target = alp, cop_target = cop;
    for(auto p : problems){
        alp_target = max(alp_target,p[0]);
        cop_target = max(cop_target,p[1]);
    }
    cout << alp_target << " " << cop_target;
    for(int i=0;i<155;i++) fill(d[i],d[i]+155,0x7f7f7f7f);
    problems.push_back({0,0,1,0,1});
    problems.push_back({0,0,0,1,1});
    d[alp][cop] = 0;
    for(int a = alp;a<=alp_target;a++){
        for(int c = cop;c<=cop_target;c++){
            for(auto problem : problems){
                int alp_req = problem[0];
                int cop_rep = problem[1];
                int alp_rwd = problem[2];
                int cop_rwd = problem[3];
                int cost = problem[4];
                if(a < alp_req || c < cop_rep) continue;
                int nxa = alp_rwd + a;
                int nxc= cop_rwd + c;
                if(nxa > alp_target) nxa = alp_target;
                if(nxc > cop_target) nxc = cop_target;
                d[nxa][nxc] = min(d[nxa][nxc], d[a][c] + cost);
            }
        }
    }
    return d[alp_target][cop_target];
}
