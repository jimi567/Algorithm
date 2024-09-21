import java.util.*;
class Solution {
    
    List<List<Integer>> adj = new LinkedList();
    int[] vis;
    public int solution(int n, int[][] edge) {
        int answer = 0;
        vis = new int[n+3];
        for(int i=0;i<n+1;i++) adj.add(new ArrayList());
        
        for(int i=0;i<edge.length;i++){
            int e1 = edge[i][0];
            int e2 = edge[i][1];
            adj.get(e1).add(e2);
            adj.get(e2).add(e1);
        }
        
        Queue<Integer> q = new LinkedList();
        q.add(1);
        vis[1] = 1;
        while(!q.isEmpty()){
            var cur = q.poll();
            for(Integer nxt : adj.get(cur)){
                if(vis[nxt] > 0) continue;
                q.add(nxt);
                vis[nxt] = vis[cur] + 1;
            }
        }
        int max =  Arrays.stream(vis).max().orElse(0);
        return (int)Arrays.stream(vis).filter(v -> v == max).count();
    }
}
