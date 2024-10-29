import java.util.*;
class Solution {
    public int solution(int[][] sizes) {
        List<Integer> bigger = new ArrayList();
        List<Integer> less = new ArrayList();
        for(int[] size : sizes){
            bigger.add(Math.max(size[0],size[1]));
            less.add(Math.min(size[0],size[1]));
        }
        return Collections.max(bigger) * Collections.max(less);
    }
}
