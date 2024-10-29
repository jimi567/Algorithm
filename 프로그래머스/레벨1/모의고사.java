
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        int n = answers.length;
        int[] a1 = {1,2,3,4,5};
        int[] a2 = {2,1,2,3,2,4,2,5};
        int[] a3 = {3,3,1,1,2,2,4,4,5,5};
        int i1 = 0,i2 = 0 ,i3 = 0;
        for(int i=0;i<n;i++){
            if(a1[i%5] == answers[i]) i1++;
            if(a2[i%8] == answers[i]) i2++;
            if(a3[i%10] == answers[i]) i3++;
        }
        int mx = Math.max(Math.max(i1,i2),i3);
        List<Integer> ans = new ArrayList<>();
        if(mx == i1) ans.add(1);
        if(mx == i2) ans.add(2);
        if(mx == i3) ans.add(3);

        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}
