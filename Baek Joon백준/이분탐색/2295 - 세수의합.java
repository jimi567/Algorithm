import java.io.*;
import java.util.*;
public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n,m;
    static Integer arr[];

    static int sum[];
    static int ans;
    static int bs(int target){
        int start = 0;
        int end = sum.length - 1;
        int mid = (start + end) / 2;
        while(start<=end){
            if(sum[mid]==target) return mid;
            else if(sum[mid] < target){
                start = mid + 1;
                mid = (start + end) / 2;
            }
            else if(sum[mid]> target){
                end = mid - 1;
                mid =(start + end) / 2;
            }
        }
        return -1;
    }
    static void solution(){
        sum = new int[n*n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                sum[(n*i)+j] = (arr[i] + arr[j]);
        Arrays.sort(arr);
        Arrays.sort(sum);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(bs(arr[i] - arr[j]) != -1){
                    System.out.println(arr[i]);
                    System.exit(0);
                }
            }
        }
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        Set<Integer> set = new TreeSet<>();
        for(int i=0;i<n;i++) set.add(Integer.parseInt(br.readLine()));
        arr = set.toArray(new Integer[n]);
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
