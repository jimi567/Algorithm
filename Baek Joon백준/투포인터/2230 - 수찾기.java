import java.io.*;
import java.util.*;
public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static int arr[];
    static int ans = 0x7f7f7f7f;
    static void solution(){
        Arrays.sort(arr);
        int en=0;
        for(int st=0;st<n;st++){
            while(en < n && arr[en]-arr[st] < m) en++;
            if(en == n) break;
            ans = Math.min(ans,arr[en]-arr[st]);
        }
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = Integer.parseInt(br.readLine());
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
