import java.io.*;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int k;
    static int[] seq;

    static int[] arr;

    static boolean exist(int num){
        return Arrays.stream(arr).
                anyMatch(it -> it == num);
    }
    static int removeIndex(int st){
        List<Integer> next = IntStream.range(st + 1, k)
                .map(i -> seq[i])
                .boxed()
                .collect(Collectors.toList());

        for(int i=0;i<n;i++){
            if(next.contains(arr[i])) continue;
            return i;
        }
        List<Integer> nows = Arrays.stream(arr)
                .boxed()
                .collect(Collectors.toList());

        for(int i=0;i<next.size();i++){
            if(nows.size() == 1) break;
            nows.remove(next.get(i));
        }
        for(int i=0;i<n;i++){
            if(arr[i] == nows.get(0)){
                return i;
            }
        }
        return 0;
    }
    static void solutions(){
        int cnt = 0;
        int using = 0;
        for(int i=0;i<k;i++){
            if(exist(seq[i])) continue;
            if(using < n){
                arr[using++] = seq[i];
                continue;
            }
            cnt++;
            arr[removeIndex(i)] = seq[i];
        }
        System.out.println(cnt);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        seq = new int[k];
        for(int i=0;i<k;i++) seq[i] = Integer.parseInt(st.nextToken());
        arr = new int[n];
    }

    public static void main(String[] args) throws IOException {
        input();
        solutions();
    }
}

