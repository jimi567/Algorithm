import java.io.*;
import java.util.*;
public class Main {
    static class pos{
        int x;
        int y;
        int time;
        boolean destroy;

        pos(int x,int y,int time, boolean destroy){
            this.x = x;
            this.y = y;
            this.time = time;
            this.destroy = destroy;
        }
    }
    static char area[][];
    static boolean vis[][][];
    static int[] dx = {0,0,-1,1};
    static int[] dy = {1,-1,0,0};
    static Queue<pos> q;
    static int n;
    static int m;

    public static void main(String[] args) throws Exception{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            StringTokenizer st = new StringTokenizer(br.readLine());

            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());

            area = new char[n][m];
            vis = new boolean[n][m][2];
            for(int i=0;i<n;i++) {
                area[i] = br.readLine().toCharArray();
            }
            q = new LinkedList<pos>();
            q.add(new pos(0,0,1,false));
            vis[0][0][0] = true; vis[0][0][1] = true;

            while (!q.isEmpty()) {
                pos cur = q.poll();
                if (cur.x == n - 1 && cur.y == m - 1) { //목적지 도착
                    bw.write(String.valueOf(cur.time));
                    bw.flush();
                    bw.close();
                    return;
                }
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                    if (area[nx][ny] == '0') { //벽이아니면
                        if (!cur.destroy && !vis[nx][ny][0]) { //아직안부수고 안부순상태에서의 방문표시가 없으면
                            q.add(new pos(nx, ny, cur.time + 1, false)); //큐에 푸쉬해주고
                            vis[nx][ny][0] = true; //방문표시
                        } else if (cur.destroy && !vis[nx][ny][1]){ //부쉈으면
                            q.add(new pos(nx, ny, cur.time + 1, true));
                            vis[nx][ny][1] = true;
                        }
                    } else { //ㅂ벽만나면
                        if(!cur.destroy && !vis[nx][ny][0]) { //파괴 권한이있으면
                            q.add(new pos(nx, ny, cur.time + 1, true));
                            vis[nx][ny][1] = true;
                        }
                    }
                }
            }
            bw.write(String.valueOf(-1));
            br.close();
            bw.flush();
            bw.close();
    }
}
