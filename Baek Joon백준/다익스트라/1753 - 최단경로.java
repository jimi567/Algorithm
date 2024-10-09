import java.io.*;
import java.util.*;

public class Main {
    static List<Pair>[] adj;
    static int v;
    static int e;
    static int k;

    static class Pair implements Comparable<Pair>{
        int cost,nxt;

        public Pair(int cost,int nxt){
            this.cost = cost;
            this.nxt = nxt;
        }

        @Override
        public int compareTo(Pair o) {
            return this.cost - o.cost;
        }
    }

    static void solutions(){
        var pq = new PriorityQueue<Pair>();
        var d = new int[v+10];
        Arrays.fill(d,0x3fffffff);
        for (Pair p : adj[k]) {
            if(d[p.nxt] > p.cost){
                pq.add(p);
                d[p.nxt] = p.cost;
            }
        }
        d[k] = 0;
        while(!pq.isEmpty()){
            var cur = pq.poll();
            if(d[cur.nxt] != cur.cost) continue;
            for(var nxt : adj[cur.nxt]){
                if(cur.cost + nxt.cost < d[nxt.nxt]){
                    pq.add(new Pair(cur.cost + nxt.cost , nxt.nxt));
                    d[nxt.nxt] = cur.cost + nxt.cost;
                }
            }
        }

        for(int i=1;i<=v;i++){
            if(d[i] == 0x3fffffff) System.out.println("INF");
            else System.out.println(d[i]);
        }
    }


    static void input() throws IOException {
        try(var br = new BufferedReader(new InputStreamReader(System.in))){
            var st = new StringTokenizer(br.readLine());
            v = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            k = Integer.parseInt(st.nextToken());
            adj = new ArrayList[v+10];
            for(int i=1;i<=v;i++) adj[i] = new ArrayList<>();
            for(int i=0;i<e;i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                adj[u].add(new Pair(w,v));
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solutions();
    }
}
