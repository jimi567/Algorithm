import java.io.*;
import java.util.*;


public class Main {
    static int n;

    static int[][] task ;
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        task = new int[n][2];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            task[i][0] = Integer.parseInt(st.nextToken());
            task[i][1] = Integer.parseInt(st.nextToken());
        }
    }
    //이런 배정문제는 끝나는 시간 기준으로 정렬  그리드 알고리즘은 어떤것을 기준으로 정렬하느냐에 따라 푸는경우가 있음
    static void solution(){
        //종료 시간 기준 정렬하되, 시작하자마 끝나는 예외로 인해 종료시간이 같으면 시작시간 기준으로 종료
        //ex (2,2) (1,2) 첫번째가 먼저오게되면 2개의 task를 처리할수있음에도 하나의 task만 처리하게됨
        Arrays.sort(task, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if(o1[1] == o2[1]) return o1[0] - o2[0]; //종료시간이 같으면 시작시간이 빠른거
                return o1[1] - o2[1]; //종료시간이 빠른거
            }
        });

        int ret = 0;
        int t = 0; //이전 회의 종료시간
        for(int i=0;i<n;i++){
            if(t > task[i][0]) continue; //회의 시작시간보다 이전 회의 종료시간이 크면 갱신x
            t = task[i][1];
            ret++;
        }
        System.out.println(ret);
    }
    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
