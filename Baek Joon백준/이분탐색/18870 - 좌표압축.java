import java.io.*;
import java.util.*;
public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static Integer arr[];
    static int ans = 0x7f7f7f7f;

    static int bs(Integer[] sa,int target ){
        int st = -1;
        int en = sa.length-1;
        while(st<=en){
            int mid = (st + en) / 2;

            if(sa[mid] == target) return mid;
            else if(sa[mid] > target) en = mid-1;
            else st = mid+1;
        }
        return -1;
    }
    static void solution(){
        //중복제거
        Set<Integer> set = new HashSet<>(Arrays.asList(arr));
        Integer sa[] = set.toArray(set.toArray(new Integer[0]));
        Arrays.sort(sa);
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            int idx = bs(sa,arr[i]);
            if(idx != -1) sb.append(idx + " ");
            else sb.append(0+" ");
        }
        System.out.println(sb);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new Integer[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
