import java.util.*;
class Solution {
    int[][] dp;
    public int solution(int alp, int cop, int[][] problems) {
        int targetA = alp, targetC = cop;
        for(int[] problem : problems){
            targetA = Math.max(targetA, problem[0]);
            targetC = Math.max(targetC, problem[1]);
        }
        if(alp == targetA && cop == targetC) return 0;
        dp = new int[targetA * 2 + 10][targetC * 2 + 10];
        for(int i=0;i<=targetA * 2; i++) Arrays.fill(dp[i],0x7f7f7f7f);
        for(int i=0;i<=alp;i++){
            for(int j=0;j<=cop;j++){
                dp[i][j] = 0;
            }
        }
        for(int a = alp; a < targetA * 2 - 1; a++){
            for(int c = cop; c < targetC * 2 - 1; c++){
                dp[a + 1][c] = Math.min(dp[a][c] + 1, dp[a+1][c]);
                dp[a][c+1] = Math.min(dp[a][c] + 1, dp[a][c+1]);
                for(int[] problem : problems){
                    int alp_req = problem[0];
                    int cop_req = problem[1];
                    int alp_rwd = problem[2];
                    int cop_rwd = problem[3];
                    int cost = problem[4];
                    if(a < alp_req || c < cop_req) continue;
                    int nextA = a + alp_rwd;
                    int nextC = c + cop_rwd;
                    if(nextA > targetA) nextA = targetA;
                    if(nextC > targetC) nextC = targetC;
                    dp[nextA][nextC] = Math.min(dp[a][c] + cost, dp[nextA][nextC]);
                }
            }
        }
    
        return dp[targetA][targetC];
    }
}
