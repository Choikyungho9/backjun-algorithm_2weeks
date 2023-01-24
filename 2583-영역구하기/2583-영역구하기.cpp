//https://www.acmicpc.net/problem/2583
#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int mapp[104][104], visited[104][104];
int xx1, yy1, xx2, yy2, nx, ny;

int dy[4] = {-1, 0 , 1, 0};
int dx[4] = {0, 1, 0, -1 };

// 배열을 만들어야하므로 int 타입의 vector 생성한다. 
vector<int> ans;

// dfs 횟수 세는 방법 
int dfs(int y, int x) {
	visited[y][x] = 1;
	// int형 dfs 
	// cnt = 1부터 
	int cnt = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n ) continue;
		if (visited[ny][nx] == 1) continue;
		if (mapp[ny][nx] == 1) continue;
		// cnt += dfs(ny, nx) <- 1씩 더해감
		cnt += dfs(ny, nx);
	}
	// 리턴값은 계속 1씩 증가.
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> m >> n >> k; 
	// k개 줄의 입력을 받아서 
	for (int i = 0; i < k; i++) {
		cin >> xx1 >> yy1 >> xx2 >> yy2;
		// x, y 지도 만들기 
		for (int x = xx1; x < xx2; x++) {
			for (int y = yy1; y < yy2; y++) {
				mapp[y][x] = 1;
			}
		}
	}
	// 지도 돌때는 무조건 안쪽이 x범위 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mapp[i][j] != 1 && visited[i][j] == 0) {
				ans.push_back(dfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto a : ans) cout << a << ' ';
}


