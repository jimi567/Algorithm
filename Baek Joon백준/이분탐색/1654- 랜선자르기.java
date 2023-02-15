import java.io.*;
import java.util.*;
public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static int[] a;
    static int[] b;
    static int ans = 0x7f7f7f7f;

    static boolean check(long cut){
        int cnt = 0;
        for(int i=0;i<n;i++) cnt += a[i]/cut;
        return cnt>=m;
    }

    static void solution(){
        long st = 0;
        long en = (1<<31) - 1;
        while(st<en){
            long mid = (st+en+1) / 2;
            if(check(mid)) st = mid;
            else en = mid - 1;
        }
        System.out.println(st);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        a = new int[n];
        for(int i=0;i<n;i++) a[i] = Integer.parseInt(br.readLine());
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
