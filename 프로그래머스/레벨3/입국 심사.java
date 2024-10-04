import java.util.*;
class Solution {
    
    public long solution(long n, int[] times) {
        long answer = 0;
        Arrays.sort(times);
        long st = 0;
        long en = times[times.length - 1] * n;
        // 0 60 30 6
        // 0 30 15 3
        // 15 30 22 5
        // 22 30 26 5
        // 26 30 28 6
        // 26 28 27 5
        
        while(st < en){
            long m = (st + en) / 2;
            long comp = 0;
            for(long t : times){
                comp += m / t;
            }
            if(comp >= n){
                en = m;
                answer = m;
            }
            else {
                st = m + 1;
            }
        }
        return answer;
    }
}
