//https://www.acmicpc.net/problem/2468 
#include <bits/stdc++.h>
using namespace std;
int n , answer;
int mapp[101][101], visited[101][101];
int ny, nx; 
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void dfs(int y , int x, int depth ) {
	visited[y][x] = 1; // 방문체크부터
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		// 오버플로우, 언더플로우 체크
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			// 깊이보다 크고, 방문 안했으면 -> dfs 재귀 
		if (mapp[ny][nx] > depth && !visited[ny][nx]) dfs(ny, nx, depth);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// 지도 만들기
	cin >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mapp[i][j];
		}
	}
	// 높이 d 는 1이상 100 이하의 정수이다.
	for (int d = 1; d < 101; d++) {
		// 높이가 1씩 증가할 때마다 배열 초기화시켜야됨.
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		// 높이가 1씩 증가할 때마다 맨처음 cnt 0으로 초기화
		int cnt = 0;
		// 지도 탐색 ( 높이 증가 후 지도 탐색 반복 ) 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// 방문한 곳이 높이 d보다 크고 , 방문 체크 안되있으면
				if (mapp[i][j] > d && !visited[i][j]) {
					// 연결된곳 싹다 탐색하게 dfs 함수 호출 
					dfs(i, j, d);
					// dfs 가 모두 다 끝났으면 , cnt ++ 
					cnt++;
				}
			}

		}
		// 지도 탐색 다 끝나고 ans 와 cnt 비교해서 최대값 갱신 
		answer = max(answer, cnt);
	}
	cout << answer << '\n';
	return 0;
}