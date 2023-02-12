import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static int arr[];
    static int targets[];
    static int ans;
    static int bs(int target){
        int start = 0;
        int end = arr.length - 1;
        int mid = (start + end) / 2;
        while(start<=end){
            if(arr[mid] == target) return 1;
            else if(arr[mid] < target){
                start = mid + 1;
                mid = (start + end) / 2;
            }
            else if(arr[mid] > target){
                end = mid - 1;
                mid =(start + end) / 2;
            }
        }
        return 0;
    }
    static void solution(){
        Arrays.sort(arr);
        for(int i=0;i<m;i++){
           System.out.println(bs(targets[i]));
        }
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<n;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        targets = new int[m];
        for(int i=0;i<m;i++){
            targets[i] = Integer.parseInt(st.nextToken());
        }
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
