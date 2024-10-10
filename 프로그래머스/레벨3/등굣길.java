import java.util.*;
class Solution {
    int mod = 1_000_000_007;
    int[][] d;
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        d = new int[n+1][m+1];
        boolean[][] isPud = new boolean[n+1][m+1];
        for(int[] p : puddles) isPud[p[1]][p[0]] = true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 || j == 0) isPud[i][j] = true;
            }
        }
        d[1][1] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1 && j ==1 || isPud[i][j]) continue;
                int val = 0;
                if(!isPud[i-1][j]) val += d[i-1][j];
                if(!isPud[i][j-1]) val += d[i][j-1];
                d[i][j] = val % mod;
            }
        }
        
        // for(int i=1;i<=n;i++){
        //     System.out.println();
        //     for(int j=1;j<=m;j++){
        //         System.out.printf(d[i][j] + " ");
        //     }
        // }
        
        return d[n][m];
    }
}
