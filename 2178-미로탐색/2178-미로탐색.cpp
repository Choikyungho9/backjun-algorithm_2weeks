// https://www.acmicpc.net/problem/2178

#include <bits/stdc++.h>
using namespace std; 
//지도의 행.열 개수 받을때는 const int 
const int max_n = 104;
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	// 입력이 띄어쓰기 없이 따닥따닥 들어올때는 scanf(%d 를 쓴다)
	scanf("%d %d", &n, &m);
	// for문 돌면서 입력받기 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	queue< pair<int, int> > q;
	// visited에 방문 처리를 하고 -> q.push (시작점) 이거는 무조건 필수암기 
	visited[0][0] = 1;
	q.push({ 0,0 });
	
	while (q.size()) {
		// y, x좌표를 뽑아낸다. (q의 맨 앞에서 뽑아냄) 
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;	// 방문한 자리면 continue;
			// 다음 좌표는 현재 좌표 + 1로 업데이트 해준다. 
			visited[ny][nx] = visited[y][x] + 1;
			// q에 다음 좌표를 넣는다. 
			q.push({ ny, nx });
		}
	}
	// 맨 마지막 요소를 출력한다. 
	printf("%d", visited[n - 1][m - 1]);
	return 0;
}