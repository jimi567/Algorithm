import java.util.*;

class Solution {
    int[][] computers;
    int[] ppids = new int[202];
    boolean[][] vis = new boolean[202][202];
    
    public int solution(int n, int[][] computers) {
        int answer = 0;
        this.computers = computers;
        for(int i=0;i<n;i++) {
            ppids[i] = i;
            vis[i][i] = true;
        } 
        for(int i=0;i<n;i++) findPPID(i);
        
        for(int i=0;i<n;i++) 
            if(ppids[i] == i) 
                answer++;
        
        return answer;
    }
    
    private int findPPID(int now){
        int[] conn = computers[now];
        for(int nxt= 0; nxt<conn.length; nxt++){
            if(conn[nxt] == 0) continue;
            if(vis[now][nxt]) continue;
            vis[now][nxt] = true;
            int nxtPPID = findPPID(nxt);
            if(nxtPPID < ppids[now]) ppids[now] = nxtPPID;
        }
        return ppids[now];
    }
}
