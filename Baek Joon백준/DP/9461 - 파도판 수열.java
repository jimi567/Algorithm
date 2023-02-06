import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int arr[];
    static int ans;

    static void solution(){
        long d[] = new long[101]; //d[i] = p(i);
        d[1] = 1; d[2] = 1; d[3] = 1;
        for(int i=4;i<=100;i++) d[i] = d[i-3] + d[i-2];
        for(int i=0;i<n;i++) System.out.println(d[arr[i]]);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
    }
        public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
