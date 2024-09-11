import java.util.*;

//문제가 억까가 심해.. 출발지랑 도착지가 같은 항공권이 여러 개 일 수 가있음..
class Solution {
    String[] ans;
    boolean[] vis;
    String[][] tc;
    int n;
    
    public String[] solution(String[][] tickets) {
        this.tc = tickets;
        this.vis = new boolean[tickets.length+10];
        dfs("ICN", new LinkedList<String>(List.of("ICN")));
        return ans;
    }
    
    
    private void dfs(String start, List<String> path){
        if(check()){
            String[] temp = path.stream().toArray(String[]::new);
            if(ans == null || Arrays.compare(temp,ans) < 0)
                ans = temp;
            return;
        }
        for(int i=0;i<tc.length;i++){
            String st = tc[i][0];
            String en = tc[i][1];
            if(!st.equals(start)) continue;
            if(vis[i]) continue;
            vis[i] = true;
            path.add(en);
            dfs(en,path);
            path.remove(path.size() - 1);
            vis[i] = false;
        }
        
    }
    private boolean check(){
        for(int i=0;i<tc.length;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
}
