import java.io.*;
import java.util.*;

//백트래킹을 이용한 풀이
public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int t[],p[];
    static int ans;


    static void solution(int day,int sum){
        if(day == n){ //base condition : 최댓값 갱신
            ans = Math.max(ans,sum);
            return;
        }
        if(day>n) return; //날짜가 n보다 커지면 일 수행 못하니깐 그냥 return
        solution(day + t[day],sum+p[day]); //해당날의 일을 선택하는경우
        solution(day+1,sum); //선택안하는 경우
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        t = new int[n];
        p = new int[n];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            t[i] = Integer.parseInt(st.nextToken());
            p[i] = Integer.parseInt(st.nextToken());
        }
    }
        public static void main(String[] args) throws IOException {
            input();
            solution(0,0);
            System.out.println(ans);
    }
}
//DP
public class Resign2 {
	/**
	 * 백준 15486 퇴사2 (https://www.acmicpc.net/problem/15486)
	 */
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(reader.readLine());
		
		int[] t = new int[n];
		int[] p = new int[n];
		
		StringTokenizer st;
		for (int i=0; i<n; i++) {
			st = new StringTokenizer(reader.readLine());
			
			t[i] = Integer.parseInt(st.nextToken());
			p[i] = Integer.parseInt(st.nextToken());
		}
		
		//dp : N일에 얻을 수 있는 최대 수익
		int[] dp = new int[n+1];
		
		//점화식
		//현재 날짜에서 소요 시간과 비용을 더해 dp에 저장한다.
		//이후, 중복될 때 최대값을 넣는다.
		//dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		
		for (int i=0; i<n; i++) {
			if (i + t[i] <= n) {
				//날짜가 범위를 넘어가지 않는 경우
				dp[i + t[i]] = Math.max(dp[i + t[i]], dp[i] + p[i]);
			}
			//현재 경우의 수가 0일 수 있기 때문에 이전의 최대값을 넣어줌.
			//해당 날짜에 일할 수 없다면, 이전까지 일한 최대 수당을 넣어주어야 한다.
			dp[i+1] = Math.max(dp[i+1], dp[i]);
		}
		System.out.println(dp[n]);
		
	}//main
}//Resign2
