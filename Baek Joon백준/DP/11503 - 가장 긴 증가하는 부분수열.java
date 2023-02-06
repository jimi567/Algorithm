import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int arr[];
    static int ans;

    static void solution(){
        int d[] = new int[n]; //i번째 인덱스에 도달했을때, arr[i]보다 작은 증부수 길이
        d[0] = 1;
        for(int i=1;i<n;i++){
            d[i] = 1; //증부수의 길이에 본인은 포함함
            for(int j=0;j<=i;j++){
                if(arr[i] > arr[j]){
                    d[i] = Math.max(d[i],d[j]+1);
                }
            }
        }
        //for(int i=0;i<n;i++) System.out.print(d[i] + " ");
        for(int i=0;i<n;i++) ans = Math.max(ans,d[i]);
        System.out.println(ans);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[n];
        for(int i=0;i<n;i++) arr[i] = Integer.parseInt(st.nextToken());
    }
        public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
