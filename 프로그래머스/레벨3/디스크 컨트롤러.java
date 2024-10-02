import java.util.*;
class Solution {
    class Job implements Comparable<Job> {
        int s,len, now;
        Job(int s, int len, int now){
            this.s = s;
            this.len = len;
            this.now = now;
        }
        
        public boolean canStart(){
            return this.now >= this.s;
        }
        
        public int compareTo(Job o){
            if(this.canStart() && !o.canStart()) return 1;
            if(o.canStart() && !this.canStart()) return -1;
            if(o.canStart() && this.canStart())
                return this.len < o.len ? 1 : -1;
            if(this.s < o.s) return 1;
            if(o.s < this.s) return -1;
            return this.len < o.len ? 1 : -1;
        }
    }
    public int solution(int[][] jobs) {
        PriorityQueue<Job> pq = new PriorityQueue(Collections.reverseOrder());
        for(int[] job : jobs){
            pq.add(new Job(job[0],job[1],0));
        }
        int sum = 0;
        int now = 0;
        Queue<Job> q = new LinkedList();
        while(!pq.isEmpty()){
            while(!pq.isEmpty()){
                var t = pq.poll();
                q.add(new Job(t.s, t.len, now));
            }
            while(!q.isEmpty()){
                pq.add(q.poll());
            }
            var cur = pq.poll();
            if(cur.s > now) now = cur.s;
            sum += now + cur.len - cur.s;
            now += cur.len;
        }
        
        return sum / jobs.length;
    }
}
