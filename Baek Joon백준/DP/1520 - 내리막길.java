import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;

    static int r;
    static int c;
    static int[][] arr;
    //0,0 -> x,y로 갈 수 있는 경우의 수
    static int[][] dp;

    static int[][] vis;

    static int[] dx = {1,0,-1,0};

    static int[] dy = {0,1,0,-1};


    static void solutions(){
        System.out.println(dfs(r-1,c-1));
    }

    private static int dfs(final int x, final int y) {
        if(x == 0 && y == 0) return 1;
        if(vis[x][y] == 1) return dp[x][y];
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(OOB(nx,ny)) continue;
            if(arr[x][y] >= arr[nx][ny]) continue;
            dp[x][y] += dfs(nx,ny);
        }
        vis[x][y] = 1;
        return dp[x][y];
    }

    private static boolean OOB(int x,int y){
        return x< 0 || x>= r || y<0 || y>=c;
    }

    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        arr = new int[r+1][c+1];
        for(int i=0;i<r;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<c;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        vis = new int[r+1][c+1];
        dp = new int[r+1][c+1];
    }

    public static void main(String[] args) throws IOException {
        input();
        solutions();
    }
}

