//내가 짠거
// 각 치킨집이 치킨거리로 배달하는 집의 갯수를 구하고 (단골집)
// m개가 될떄까지 단골집의 갯수가 작은 치킨집을 치킨벡터에서 삭제해나가는방식
// 결론적으로 틀림... 그냥 각 치킨집에서 조합으로 m개 고르고 모든 조합에 따른 도시치킨거리를 구하고 그 최소가될떄를 찾으면됨
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int area[55][55];
int n, m;
vector<pair<int,pair<int, int>>> chicken; // 치킨집 번호, 치킨의 좌표
vector<pair<int, int>> home;// 집좌표

pair<int,int>  MinCDis(int x,int y) { //각 집마다 가장 가까운 치킨집과, 치킨거리를 리턴
    pair<int, int> ret;
    int mind = 105;
    int dist = 0;
    for (int i = 0; i < chicken.size(); i++) {
        dist = abs(chicken[i].S.F - x) + abs(chicken[i].S.S - y);
        if (mind > dist) {
            mind = dist;
            ret.S = mind;
            ret.F = chicken[i].F;
        }
    }
    return ret;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    int idx = 0; //치킨집 번호
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            if (area[i][j] == 1) home.push_back({ i,j });
            else if (area[i][j] == 2) chicken.push_back({ idx++,{ i,j } });
        }
    }
    int arr[15]; //인덱스는 치킨집 넘버, 데이터는 해당 치킨집이 치킨거리가되는 집의 갯수
    fill(arr, arr + 15, 105);
    for (int i = 0; i < home.size(); i++) {
        pair<int, int> tmp = MinCDis(home[i].F, home[i].S);
        arr[tmp.F]++;
    }
    while (m < chicken.size()) {
        int mh = 102;
        int rmidx;
        for (int i = 0; i < 15; i++) {
            if (mh >= arr[i]) {
                mh = arr[i];
                rmidx = i;
            }
        }

        chicken.erase(chicken.begin() + rmidx);
    }

    int answer = 0;
    for (int i = 0; i < home.size(); i++) {
        answer += MinCDis(home[i].F, home[i].S).S;
    }
    
    cout << answer;
}

// 치킨 집에서 m개를 고른다음 각 도시치킨거리를 구하고 그중 최소도시치킨거리를 구하는방법
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int area[55][55];
int n, m;
vector<pair<int, int>> chicken; //  치킨의 좌표
vector<pair<int, int>> home;// 집좌표


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            if (area[i][j] == 1) home.push_back({ i,j });
            if (area[i][j] == 2) chicken.push_back({ i,j });
        }
    }
    int ans = 0x7f7f7f7f;
    vector<int> conbi(chicken.size(), 0);
    fill(conbi.begin() + conbi.size() - m, conbi.end() , 1);
    do {
        int sumd = 0; //도시 치킨거리
        for (auto h : home) {
            int dist = 0x7f7f7f7f; //각 집 치킨거리
            for (int i = 0; i < chicken.size(); i++) { 
                if (conbi[i] == 1) {
                    dist = min(dist, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y)); //치킨거리 갱신
                }
            }
            sumd += dist;
        }
        ans = min(ans, sumd);
    } while (next_permutation(conbi.begin(), conbi.end()));
    cout << ans;
}
