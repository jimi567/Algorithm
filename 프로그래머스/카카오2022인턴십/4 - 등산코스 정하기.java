import java.util.*;
class Solution {
    class Pair implements Comparable<Pair>{
        int cost,v, intent;
        Pair(int cost, int v,int intent){
            this.cost = cost;
            this.v = v;
            this.intent = intent;
        }
        public int compareTo(Pair o){
            return this.cost - o.cost;
        }
    }
    List<Pair>[] adj;
    int n;
    int MAX = 10000010;
    int[][] costs;
    int[] nodes;

    public int[] solution(int n, int[][] paths, int[] gates, int[] summits) {
        this.adj = new ArrayList[n+2];
        for(int i=1;i<adj.length; i++) adj[i] = new ArrayList();
        this.nodes = new int[n+1];

        for(int i : summits) nodes[i] = 1;
        for(int i : gates) nodes[i] = 2;

        for(int[] path : paths){
            int u = path[0];
            int v = path[1];
            int w = path[2];
            adj[u].add(new Pair(w,v,MAX));
            adj[v].add(new Pair(w,u,MAX));
        }
        int[] d = new int[n+1];
        Arrays.fill(d,MAX);
        int[] a = Arrays.copyOf(d,d.length);
        PriorityQueue<Pair> pq = new PriorityQueue();
        for(int gate : gates){
            pq.add(new Pair(0,gate,0));
            d[gate] = 0;
        }

        int ansS = 0;
        int ansI = MAX;
        while(!pq.isEmpty()){
            var cur = pq.poll();
            if(d[cur.v] != cur.cost) continue;
            for(Pair nxt : adj[cur.v]){
                if(nodes[nxt.v] == 2) continue; //다른 출입구 가려고 하면 X
                if(d[nxt.v] > nxt.cost){
                    d[nxt.v]  = nxt.cost;
                    Pair next = new Pair(nxt.cost,nxt.v,Math.max(cur.intent,nxt.cost));
                    if(nodes[nxt.v] == 1) {
                        if(ansI > next.intent){
                            ansS = next.v;
                            ansI = next.intent;
                        }
                        else if(ansI == next.intent && ansS > next.v){
                            ansS = next.v;
                        }
                        continue;
                    }
                    pq.add(next);
                }
            }
        }

        return new int[]{ansS,ansI};
    }
}
