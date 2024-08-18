import java.util.*;
class Solution {
    int mxk;
    int target;
    int ans = 0;
    int[] numbers;
    void fun(int num, int k){
        if(k == mxk){
            if(num == target) ans++;
            return ;
        }
      
        fun(num + numbers[k], k+1);
        fun(num - numbers[k], k+1);
        
    }
    
    public int solution(int[] numbers, int target) {
        this.numbers = numbers;
        this.mxk = numbers.length;
        this.target = target;
        fun(0,0);
        return ans;
    }
}
