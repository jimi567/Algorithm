import java.util.*;
class Solution {
    int n;
    int[] root;
    int[] cnt;
    int getParent(int v){
        if(root[v] == v) return v;
        return root[v] = getParent(root[v]);
    }
    void union(int st, int en){
        if(st == en) return;
        st = getParent(st);
        en = getParent(en);
        if(st > en) root[st] = en;
        else if(st < en) root[en] = st;
    }
    void init() {
        for(int i=1;i<n+1;i++) {
            root[i] = i;
            cnt[i] = 0;
        }
    }
    int getDiff(){
        for(int i=1;i<n+1;i++){
            cnt[root[i]]++;
        }
        List<Integer> sizes = new ArrayList();
        for(int i=1;i<n+1;i++){
            if(cnt[i] > 0) sizes.add(cnt[i]);
        }
        return Math.abs(sizes.get(0) - sizes.get(1));
    }
    
    public int solution(int n, int[][] wires) {
        int answer = 0x7f7f7f7f;
        this.n = n;
        this.root = new int[n+1];
        this.cnt = new int[n+1];
    
        for(int i=0;i<n-1;i++){
            init();
            for(int j=0;j<n-1;j++){
                if(i==j) continue;
                union(wires[j][0], wires[j][1]);
            }
            for(int v=1;v<n+1;v++) getParent(v);
            answer = Math.min(answer,getDiff());
        }
        return answer;
    }
}
