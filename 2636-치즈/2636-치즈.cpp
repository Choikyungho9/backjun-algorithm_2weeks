// https://www.acmicpc.net/problem/2636
#include <bits/stdc++.h>
using namespace std;

int n, m, a[104][104], visited[104][104];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
// cnt: 모두 녹아서 없어지는데 걸리는 시간
// cnt2: 모두 녹기 한시간전에 남아있는 치즈조각
int cnt, cnt2;
vector < pair<int, int>> v;

//dfs : 깊이우선탐색
void dfs(int y, int x){
	visited[y][x] = 1;	// 현재 좌표 체크
	if (a[y][x] == 1) {	// 치즈 녹는점 만났을때, return
		v.push_back({ y,x }); // 기능실행
		return; // push_back하고 종료
	}
	for (int i = 0; i < 4; i++) {	//4방향 탐색
		int ny = y + dy[i];	// 다음 y좌표
		int nx = x + dx[i];	// 다음 x좌표
		if (ny < 0 || ny >= n || nx<0 || nx>m || visited[ny][nx]) continue;
		dfs(ny, nx);	// 재귀호출
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	while (true)
	{
		cnt2 = 0;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear(); // 치즈조각 개수 담을 배열
		dfs(0,0); // 4방향 탐색
		// 치즈 바깥쪽 만났을때, 맨처음 만난 좌표를 0으로 바꿔서 녹는 것을 표현
		for (pair<int, int> b : v) {
			cnt2++;
			a[b.first][b.second] = 0;
		}
		// 다 녹았는지 체크해야됨.
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 치즈가 1이니까, 0이 계속 남아있으면 종료 못시키게 flag=1로 만듬.
				if (a[i][j] != 0) flag = 1;
			}
		}
		cnt++;
		// 1은 True 0은 False
		// 50번 줄에서 flag1에 걸리지 않고 치즈가 다 녹아서 없어져서
		// flag = 0이 내려오면 , 프로그램 종료.
		if (!flag) break;
	}
	cout << cnt << "\n" << cnt2 << '\n';
}