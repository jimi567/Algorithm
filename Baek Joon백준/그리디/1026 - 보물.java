import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static Integer a[];
    static Integer b[];
    static int ans = 0;
    static void solution(){
        Arrays.sort(a);
        Arrays.sort(b,Collections.reverseOrder());
        HashMap<Integer, Integer> dic = new LinkedHashMap<Integer,Integer>();
        for(int i=0;i<n;i++){
            ans += a[i] * b[i];
        }

        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new Integer[n];
        b = new Integer[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) a[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) b[i] = Integer.parseInt(st.nextToken());
    }
        public static void main(String[] args) throws IOException {
            input();
            solution();
        }
}
