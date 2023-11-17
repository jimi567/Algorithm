#include <bits/stdc++.h>

int dist[205][205];
int adj[205][205];

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(int i=0;i<fares.size();i++){
        adj[fares[i][0]][fares[i][1]] = fares[i][2];
        adj[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = 3000000;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j])
                dist[i][j] = dist[i][k]+dist[k][j];
            }
        }
    }
    int ans = dist[s][a]+dist[s][b];
    for(int k=1;k<=n;k++){
        if(ans > dist[s][k] + dist[k][a] + dist[k][b])
                ans = dist[s][k] + dist[k][a] + dist[k][b];
    }
    return ans;
}
