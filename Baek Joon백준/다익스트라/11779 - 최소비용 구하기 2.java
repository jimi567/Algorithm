import java.io.*;
import java.util.*;

public class Main {
    static List<Pair>[] adj;
    static int n;
    static int m;
    static int s;
    static int e;

    static class Pair implements Comparable<Pair>{
        int cost,v;

        public Pair(int cost,int v){
            this.cost = cost;
            this.v = v;
        }

        @Override
        public int compareTo(Pair o) {
            return this.cost - o.cost;
        }
    }

    static void solutions(){
        int[] prev = new int[n+2];
        int[] d = new int[n+2];
        Arrays.fill(d,0x3fffffff);
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for(Pair p : adj[s]){
            if(d[p.v] > p.cost){
                pq.add(p);
                d[p.v] = p.cost;
                prev[p.v] = s;
            }
        }
        d[s] = 0;
        prev[s] = 0;
        while(!pq.isEmpty()){
            var cur = pq.poll();
            if(d[cur.v] != cur.cost) continue;;
            for(Pair nxt : adj[cur.v]){
                if(d[nxt.v] > cur.cost + nxt.cost){
                    pq.add(new Pair(cur.cost + nxt.cost, nxt.v));
                    d[nxt.v] = cur.cost + nxt.cost;
                    prev[nxt.v] = cur.v;
                }
            }
        }
        System.out.println(d[e]);
        List<Integer> path = new ArrayList<>();
        int p = prev[e];
        path.add(e);
        while(p != 0){
            path.add(p);
            p = prev[p];
        }
        System.out.println(path.size());
        for(int i = path.size()-1 ;i>= 0 ;i--){
            System.out.printf(path.get(i) + " ");
        }
    }

    static void input() throws IOException {
        try(var br = new BufferedReader(new InputStreamReader(System.in))){
            var st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            adj = new ArrayList[n+10];
            for(int i=1;i<=n;i++) adj[i] = new ArrayList<>();
            for(int i=0;i<m;i++) {
                st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                int w = Integer.parseInt(st.nextToken());
                adj[u].add(new Pair(w,v));
            }
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solutions();
    }
}
