import java.io.*;
import java.util.*;

public class Main {
    static class pos{
        int x,y;
        public pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static int map[][];
    static int dx[] = {1,-1,0,0};
    static int dy[] = {0,0,1,-1};
    static int vis[][];
    static int ans;
    //현재 빙산의 덩어리의 갯수 계산하기 bfs
    static int calcMash(){
      //방문배열 초기화
        for(int i=0;i<n;i++) Arrays.fill(vis[i],0);
        int curMash = 0;
        Queue<pos> q = new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j] <= 0 || vis[i][j] == 1) continue;
                q.add(new pos(i,j));
                vis[i][j] = 1;
                curMash++;
                while(!q.isEmpty()){
                    pos curPos = q.poll();
                    for(int dir=0;dir<4;dir++){
                        int nx = curPos.x + dx[dir];
                        int ny = curPos.y + dy[dir];
                        if( nx<0||ny<0||nx>=n||ny>=m)continue;
                        if(vis[nx][ny] == 1 || map[nx][ny] <= 0) continue;
                        q.add(new pos(nx,ny)); vis[nx][ny] = 1;
                    }
                }
            }
        }
        return curMash;
    }
  //1년 시간흐름 - 빙하녹이기
    static void afterYear(){
      //현재 맵상태를 복사한 cmap만들기
      //cmap이 없으면 -> 0 1 2 의 경우 1이 녹아서 0이되면 2도 1이됨 원래 빙하기 있던 자리도 0이돼서 빙하가 없던곳이라고 판단하기 때문
        int cmap[][] = new int[n][m];
        for(int i=0;i<n;i++) cmap[i] = Arrays.copyOf(map[i],m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( cmap[i][j] <= 0) continue;
                for(int dir =0;dir<4;dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if( nx<0||ny<0||nx>=n||ny>=m)continue;
                    if(cmap[nx][ny] <= 0) map[i][j] -= 1;
                }
            }
        }
        ans++;
    }
    static void solution(){
        while(true){
            int mash = calcMash();
            if(mash == 0) {//빙하의 덩어리가 없으면 빙하가 존재하지않는다는 의미
                System.out.println(0);
                return;
            }
            else if (mash >= 2) {
                System.out.println(ans);
                return;
            }
            afterYear();
        }
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];
        vis = new int[n][m];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
