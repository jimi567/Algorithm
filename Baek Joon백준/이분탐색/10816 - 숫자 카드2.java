import java.io.*;
import java.util.*;
public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static int[] a;
    static int[] b;
    static int ans = 0x7f7f7f7f;

    static int lb(int[] a, int target){
        int st = 0; int en = a.length;
        while(st<en){
            int mid = (st+en) / 2;
            if(a[mid] >= target) en = mid;
            else st = mid+1;
        }
        return st;
    }
    static int ub(int[] a, int target){
        int st = 0; int en = a.length;
        while(st<en){
            int mid = (st+en) / 2;
            if(a[mid] <= target) st = mid + 1;
            else en = mid;
        }
        return st;
    }
    static void solution(){
        Arrays.sort(a);
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<m;i++) ans.append(ub(a,b[i]) - lb(a,b[i]) +" ");
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        a = new int[n];
        for(int i=0;i<n;i++) a[i] = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        b = new int[m];
        for(int i=0;i<m;i++) b[i] = Integer.parseInt(st.nextToken());
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
