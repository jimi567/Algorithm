import java.util.*;
class Solution {
    
    String[] words;
    Map<String,Integer> vis = new HashMap();
    
    private boolean isNext(String s1, String s2){
        int cnt = 0;
        for(int i=0;i<s1.length();i++){
            if(s1.charAt(i) != s2.charAt(i)) cnt++;
        }
        return cnt == 1;
    }
    
    public int solution(String begin, String target, String[] words) {
        this.words = words;
        Queue<String> q = new LinkedList();
        for(String word : words){
            vis.put(word,-1);
        }
        
        if(vis.get(target) == null) return 0;
        q.add(begin);
        vis.put(begin, 0);
        while(!q.isEmpty()){
            String cur = q.poll();
            for(String word : words){
                if(!isNext(cur,word)) continue;
                if(vis.get(word) != -1) continue;
                vis.put(word , vis.get(cur) + 1);
                q.add(word);
            }
        }
        
        return vis.get(target);
    }
}
