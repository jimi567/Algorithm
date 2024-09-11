import java.util.*;
class Solution {
    
    class Pair{
        int x,y;
        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
    }
    
    int cx,cy,ix,iy;
    int[][] maps = new int[105][105];
    int[][] vis = new int[105][105];
    int[] dx = {0,1,-1,0};
    int[] dy = {1,0,0,-1};
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        this.cx = characterX;
        this.cy = characterY;
        this.ix = itemX;
        this.iy = itemY;
        
        for(int i = 0;i<rectangle.length;i++){
            int x1 = rectangle[i][0] * 2;
            int y1 = rectangle[i][1] * 2;
            int x2 = rectangle[i][2] * 2;
            int y2 = rectangle[i][3] * 2;
            
            for(int x=x1;x <= x2;x++){
                for(int y = y1;y <= y2;y++){
                    if(maps[x][y] == 2) continue; //다른 사각형 내부면 못지나감
                    maps[x][y] = 2;
                    if(x == x1 || x == x2 || y == y1 || y == y2) maps[x][y] = 1;
                }
            }
        }
    
        Queue<Pair> q = new LinkedList();
        q.add(new Pair(cx * 2,cy * 2));
        vis[cx * 2][cy * 2] = 1;
        while(!q.isEmpty()){
            var cur = q.poll();
            for(int dir = 0;dir<4;dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || ny < 0 || nx > 100 || ny > 100) continue;
                if(maps[nx][ny] != 1 || vis[nx][ny] > 0) continue;
                q.add(new Pair(nx,ny));
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
            }
        }
    
        return (vis[ix * 2][iy * 2] - 1) / 2;
    }
}
