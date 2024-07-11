import java.util.*;

class Solution {
    
    private int[][] dist = new int[202][202];
    
    public int solution(int n, int s, int a, int b, int[][] fares) {
        for(int[] road : fares){
            dist[road[0]][road[1]] = road[2];
            dist[road[1]][road[0]] = road[2];
        }
   
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++) {
                if(i==j) dist[i][j] = 0;
                else if(dist[i][j] > 0) continue;
                else dist[i][j] = 10000000;
            }
        }
        
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
        int ans =  dist[s][a] + dist[s][b];
       
        for(int i=1;i<=n;i++){
            if(ans > dist[s][i] + dist[i][a] + dist[i][b])
                ans = dist[s][i] + dist[i][a] + dist[i][b];
        }
        
        return ans;
    }
}
