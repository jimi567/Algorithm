import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int t[],p[];
    static int ans;


    static void solution(){
        int d[] = new int[n+1]; //d[i] = i번째날 벌 수 있는 최대 수익;
        int max = 0;
        for(int i=0;i<n;i++){
            d[i] = Math.max(max,d[i]);
            if(n>=i+t[i]){
                d[i+t[i]] = Math.max(d[i+t[i]],d[i]+p[i]);
             }
            max = Math.max(d[i],max);
        }
        System.out.println(Math.max(d[n-1],d[n]));
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        t = new int[n];
        p = new int[n];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            t[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
        }
    }
        public static void main(String[] args) throws IOException {
            input();
            solution();
        }
}

