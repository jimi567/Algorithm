import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static Set<String> arr;
    static int ans;

    static void solution(){
        arr.stream().sorted(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if (o1.length() != o2.length()) return o1.length() - o2.length();
                return o1.compareTo(o2);
            }
        }).forEach(System.out::println);
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new HashSet<String>();
        for (int i = 0; i < n; i++) arr.add(br.readLine());
    }
        public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
