import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static String ans = "3";
    static char num[] = {'1','2','3'};
    static void go(String k){
        /*      if(n == k.length()) {
            if(ans.compareTo(k) > 0) ans = k;
            return;
        }*/
        if(n == k.length()) { //num이 1부터 시작하므로 처음 나온 값이 최소가됨 그래서 바로 exit해줘도됨..
            System.out.println(k);
            System.exit(0);
        }
        for (int i = 0; i < 3; i++) {
            boolean flag = true;
            String tmp = k + num[i];
            for (int l = 1; l <= tmp.length()/2; l++) {
                String sub1 = tmp.substring(tmp.length() - l * 2, tmp.length() - l); //앞부분
                String sub2 = tmp.substring(tmp.length() - l, tmp.length()); //뒷부분
                if (sub1.equals(sub2)) flag = false;
            }
            if (flag) go(tmp);
        }
    }
    static void solution(){
        go("1");
      //System.out.println(ans);
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
