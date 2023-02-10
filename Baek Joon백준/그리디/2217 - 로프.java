import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static Integer arr[];

    static int ans;
    static void solution(){ //k는 한 팀이고른 팀원 수
        Arrays.sort(arr, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2-o1;
            }
        });

        for(int i=0;i<n;i++){
            ans = Math.max(ans,arr[i]*(i+1));
        }
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new Integer[n];
        for(int i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());

    }
        public static void main(String[] args) throws IOException {
            input();
            solution();
        }
}
