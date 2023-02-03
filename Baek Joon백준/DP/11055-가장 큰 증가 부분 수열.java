import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int arr[];
    static int ans;

    static void solution(){
        int d[] = new int[n]; 
        d[0] = arr[0];
        for(int i=1;i<n;i++){
            d[i] = arr[i];
            for(int j=0;j<i;j++){
                if(arr[i] > arr[j]){
                    d[i] = Math.max(d[i],d[j] + arr[i]);
                }
            }
        }
        for(int i=0;i<n;i++) ans = Math.max(ans,d[i]);
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
