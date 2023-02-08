import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static long ans;


    static void solution(){
        int mod = 1000000000;
        long d[][] = new long[n][10]; //d[i] = i번째 자릿수의 0~8까지의 계단수 % mod
        d[0][0] = 0;
        for(int i=1;i<10;i++) d[0][i] = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<10;j++){
                if(j == 0) d[i][j] = d[i-1][1] % mod;
                else if(j==9) d[i][j] = d[i-1][8] % mod;
                else d[i][j] = (d[i-1][j-1] + d[i-1][j+1]) % mod;
            }
        }
        for(int i=0;i<10;i++) ans+=d[n-1][i] % mod;
        System.out.println(ans % mod);

    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

    }
        public static void main(String[] args) throws IOException {
            input();
            solution();
        }
}

