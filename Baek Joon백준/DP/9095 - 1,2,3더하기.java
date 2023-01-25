import java.io.*;
import java.util.*;
public class Main {
    static int loop,n;
    static int[] arr = new int[12];
    
  //필드값 arr[i] = arr[i-3]+arr[i-2]+arr[i-1]
  //초기값 1 = 1, 2 = 2, 3 = 4,
    public static void main(String[] args) throws Exception{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            loop = Integer.parseInt(br.readLine());
            arr[1] = 1;
            arr[2] = 2;
            arr[3] = 4;
            for(int i=4;i<12;i++){
                arr[i] = arr[i-3]+arr[i-2]+arr[i-1];
            }
            for(int i=0;i<loop;i++){
                n = Integer.parseInt(br.readLine());
                System.out.println(arr[n]);
            }
            br.close();
    }
}
