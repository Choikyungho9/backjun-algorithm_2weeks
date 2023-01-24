//https://www.acmicpc.net/problem/1012
#include <bits/stdc++.h>

using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int t, m, n, k, y, x, ny, nx, answer;
int mapp[51][51];
bool visited[51][51];

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (mapp[ny][nx] == 1 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
}


int main() {
	cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		//  fill(&arr[0][0], &arr[MAX - 1][MAX], 0);
		fill(&mapp[0][0], &mapp[51-1][51], 0);
		fill(&visited[0][0], &visited[51 - 1][51], 0);
		answer = 0;
		cin >> m >> n >> k;
		// 입력받아서 지도 만드는 과정 
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			// 2차원 배열에서는 x / y 꺼꾸로 해서 a배열의 인덱스로!
			mapp[y][x] = 1;
		}

		// 그래프 탐색은 무조건 안쪽 for문이 x축이 되게!! 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				// 여기서는 i, j 그대로 쓴다.
				if (mapp[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					// dfs 다돌면 ~ 
					answer += 1;
				}
			}
		}
		cout << answer << '\n';
	}

}