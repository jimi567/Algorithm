import java.io.*;
import java.util.*;
public class Main {
    static class pair{
        int x,y;
        pair(int x,int y){
            this.x = x;
            this.y = y;
        }
    }

    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static char arr[][];
    static boolean used[][];
    static boolean vis[][] = new boolean[5][5];//bfs용
    static int dx[] = {1,0,-1,0};
    static int dy[] = {0,1,0,-1};
    static int ans;

    static void conbi(int k,int st){
        if(k==7) {
            if(check()) ans++;
            return;
        }
        for(int i=st;i<25;i++){
            if(used[i/5][i%5]) continue;
            used[i/5][i%5] = true;
            conbi(k+1,i);
            used[i/5][i%5] = false;
        }
    }
    static boolean check(){
        boolean ret = false;
        int cntS = 0; // S파 인원수
        int cnt = 0; //연결된 갯수
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                vis[i][j] = false;
        Queue<pair> q = new LinkedList<>();
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(used[i][j]){
                    q.add(new pair(i,j));
                    vis[i][j] = true;
                    if(arr[i][j] == 'S') cntS++;
                    cnt++;
                    break;
                }
            }
            if(!q.isEmpty()) break;
        }
        while(!q.isEmpty()){
            pair cur = q.poll();
            for(int i=0;i<4;i++){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx<0||ny<0||nx>=5||ny>=5) continue;
                if(vis[nx][ny] || !used[nx][ny]) continue;
                q.add(new pair(nx,ny)); vis[nx][ny] = true;
                cnt++;
                if(arr[nx][ny] == 'S') cntS++;
            }
        }
        if(cnt == 7 && cntS>=4) ret = true;
        return ret;
    }
    static void solution(){
        conbi(0,0);
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        //n = Integer.parseInt(br.readLine());
        arr = new char[5][5];
        used = new boolean[5][5];
        for(int i=0;i<5;i++){
            arr[i] = br.readLine().toCharArray();
        }
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
