import java.io.*;
import java.util.*;


public class Main {
    static final int MAX_RANGE = 100005;
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int k;

    static int[] vis;

    static int[] dx = {-1,1};


    static void solutions(){
        Queue<Integer> q = new ArrayDeque<>();
        q.add(n);
        vis[n] = 1;
        while(!q.isEmpty()){
            var now = q.poll();
            int jx = 2 * now;
            if(jx < MAX_RANGE && vis[jx] == 0) {
                vis[jx] = vis[now];
                q.add(jx);
            }
            for(int i=0;i<2;i++){
                int nx = now + dx[i];
                if(nx < 0 || nx >= MAX_RANGE) continue;
                if(vis[nx] > 0) continue;
                vis[nx] = vis[now] + 1;
                q.add(nx);
            }
        }
        System.out.println(vis[k] - 1);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        vis = new int[MAX_RANGE];
        for (int i = 0; i < MAX_RANGE; i++)
            vis[i] = 0;
    }

    public static void main(String[] args) throws IOException {
        input();
        solutions();
    }
}

