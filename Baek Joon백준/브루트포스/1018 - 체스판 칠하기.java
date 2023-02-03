import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static String bd[];
    static int ans = 0x7f7f7f7f;

    static String bw[];
    static void solution(){
        int cnt = 0; //다시칠해야되는 판의 수
        for(int c=0;c<n-7;c++){ //밑으로 한칸씩 옮기기
            for(int r=0;r<m-7;r++) { //오른쪽으로 한칸씩 옮기기
                cnt = 0;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (bw[i].charAt(j) != bd[i + c].charAt(j+r)) cnt++;
                    }
                }
                ans = Math.min(cnt, ans);
                ans = Math.min(64 - cnt, ans); //w로 시작하는 체스판의 경우
            }
        }
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        bd = new String[n];
        for(int i=0;i<n;i++) bd[i] = br.readLine();
        bw = new String[8];
        for(int i=0;i<8;i++){
            if(i%2 == 0) bw[i] = "BWBWBWBW";
            else bw[i] = "WBWBWBWB";
        }
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
