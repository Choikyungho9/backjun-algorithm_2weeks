// https://www.acmicpc.net/problem/17298
#include<bits/stdc++.h>
using namespace std;

int n, a[1000004], ret[10000004];
stack<int> s;

int main() {
	cin >> n;
	//정답 배열을 -1로 초기화
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++) {
		// a배열에서는 3 5 2 7이 들어간다.
		// 스택에 탑은 7
		cin >> a[i];
		while (s.size() && a[s.top()] < a[i]) {
			ret[s.top()] = a[i]; // ret 정답배열에 할당.
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << ret[i] << " ";
	}
}