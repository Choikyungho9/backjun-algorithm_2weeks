// https://www.acmicpc.net/problem/1325
#include<bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int dp[10001], mx, visited[10001], n, m, a, b;

int dfs(int here) {
	// 방문체크 
	visited[here] = 1;
	// ret = 1
	int ret = 1;
	// 다음 방문 탐색
	for (int there : v[here]) {
		// 방문되있으면, pass
		if (visited[there]) continue;
		// dfs 더하고, 호출 
		ret += dfs(there);
	}
	// ret 반환
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		// dp[i]의 값에는 dfs가 몇개를 이어서 탐색하는지
		// 그 개수가 담겨져있다. 
		dp[i] = dfs(i);
		mx = max(dp[i], mx);
	}
	for (int i = 1; i <= n; i++) {
		if (mx == dp[i]) {
			cout << i << " ";
		}
	}

}