import java.io.*;
import java.util.*;
public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static int[] a;
    static int[] b;
    static int ans = 0x7f7f7f7f;
    static int bs(int target){
        int st = 0;
        int en = a.length-1;
        while(st<=en){
            int mid = (st+en) / 2;
            if(a[mid] == target) return 1;
            else if(a[mid] > target) en = mid - 1;
            else st = mid+1;
        }
        return 0;
    }
    static void solution(){
        StringBuilder ans = new StringBuilder();
        Arrays.sort(a);
        for(int i=0;i<m;i++) ans.append(bs(b[i])+" ");
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) a[i] = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(br.readLine());
        b = new int[m];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<m;i++) b[i] = Integer.parseInt(st.nextToken());
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
