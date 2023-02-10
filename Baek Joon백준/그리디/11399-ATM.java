import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static Integer a[];
    static int ans = 0;
    static void solution(){ //cpu스케줄링 STJ알고리즘
        Arrays.sort(a);
        int st = 0;
        for(int i=0;i<n;i++){
            ans += st+a[i];
            st += a[i];
        }
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new Integer[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) a[i] = Integer.parseInt(st.nextToken());
    }
        public static void main(String[] args) throws IOException {
            input();
            solution();
        }
}
