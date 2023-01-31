// https://www.acmicpc.net/problem/1068
// 리프노드의 수 
// dfs(here) : 정점
#include <string>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n, r, temp, root;
vector<int> adj[54];

// here : 현재 위치의 정점
int dfs(int here) {
	// ret : 리프노드의 수
	int ret = 0;
	// 
	int child = 0;

	// here라는 정점에서 there로 가는데, 
	// there부분에 지워지는 게 있다면 continue
	for (int there : adj[here]) {
		// there부분이 지워지는 정점 r의 경우에는 continue;
		if (there == r) continue;
		// ret은 1씩 더해질 것이다.
		ret += dfs(there);
		// 자식노드가 있으면~ child++ 2개까지도 생길수있다.
		child++;
	}
	// child ++ 하지않고 내려온 경우, 맨 끝단 정점이므로
	// ' 1 ' 을 반환한다.
	if (child == 0) return 1;
	// 모두 종료되면 최종 ret을 반환한다.
	return ret;
}


int main() {
	// 첫째줄 입력받기
	cin >> n;
	for (int i = 0; i < n; i++) {
		// 각 정점 입력받기
		cin >> temp;
		// -1입력이 들어오면, root = 0이다.
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
			
		cin >> r;
		// root노드부터 탐색할껀데, root노드가 지워지면 안되니깐, 0으로 만든다.
		if (r == root) {
			cout << 0 << "\n"; return 0;
		}
		cout << dfs(root) << "\n";
		return 0;
	}
}