import java.util.*;
class Solution {
    class Pair{
        int x,y;
        Pair(int x,int y){
            this.x = x;
            this.y = y;
        }
    }
    int[] dx = {0,1,-1,0};
    int[] dy = {1,0,0,-1};
    int[][] maps;
    int[][] vis;
    
    public int solution(int[][] maps) {
        this.maps = maps;
        this.vis = new int[102][102];
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(0,0));
        vis[0][0] = 1;
        while(!q.isEmpty()){
            var cur = q.poll();
            for(int dir = 0; dir<4;dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(OOB(nx,ny)) continue;
                if(maps[nx][ny] == 0 || vis[nx][ny] > 0) continue;
                q.add(new Pair(nx,ny));
                vis[nx][ny] = vis[cur.x][cur.y] + 1;
            }
        }
        if(vis[maps.length - 1][maps[0].length - 1] == 0) return -1;
        return vis[maps.length - 1][maps[0].length - 1];
    }
    
    private boolean OOB(int nx,int ny){
        return nx<0 || ny < 0 || nx >= maps.length || ny >= maps[0].length;
    }
}
