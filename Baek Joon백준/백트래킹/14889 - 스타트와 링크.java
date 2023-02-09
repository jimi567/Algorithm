//자바 백트래킹
import java.io.*;
import java.util.*;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int n;
    static int arr[][];
    static int used[]; //방문여부
    static long ans = 0x7f7f7f7f;
    static void solution(int st,int k){ //k는 한 팀이고른 팀원 수
        if(k==n/2){
            int start = 0, link = 0;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if( used[i] == 1 && used[j] == 1){
                        start += arr[i][j] + arr[j][i];
                    }
                    else if (used[i] == 0 && used[j] == 0){
                        link += arr[i][j] + arr[j][i];
                    }
                }
            }
            //System.out.println("score : " + start + " " + link);
            ans = Math.min(ans, Math.abs(start - link));
            return ;
        }
        for(int i=st;i<n;i++){
                if(used[i] != 0) continue;
                used[i] = 1;
                solution(i+1,k+1);
                used[i] = 0;
        }
    }
    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new int[n][n];
        used = new int[n];
        for(int i=0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }
        public static void main(String[] args) throws IOException {
            input();
            solution(0,0);
            System.out.println(ans);
        }
}

----------------------------
//c++ next_permutation
  #include <bits/stdc++.h>
using namespace std;
int n;
int a[25][25];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];

  vector<int> team(n); //i번째 사람이 소속된 팀
  fill(team.begin() + n / 2, team.end(), 1);
  int ans = 0x7f7f7f7f;
  do {
    int diff = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++){
        if(team[i] != team[j]) continue; //소속 팀이 다른 경
        if(team[i] == 0) diff += (a[i][j] + a[j][i]); //스타트팀이
        else diff -= (a[i][j] + a[j][i]); //링크팀이면
      }
    }
    ans = min(ans, abs(diff));
  } while (next_permutation(team.begin(), team.end()));
  cout << ans;
}
