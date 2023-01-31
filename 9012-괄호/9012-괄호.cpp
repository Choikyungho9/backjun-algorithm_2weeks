//https://www.acmicpc.net/problem/9012
// 짝짓기 -> 스택 

#include <bits/stdc++.h>
using namespace std;
int n;
string s;

bool check(string s) {
	stack<char> stk;
	for (char c : s) {
		if (c == '(') stk.push(c);
		else {
			// 스택이 비지 않았으면
			if (!stk.empty()) stk.pop();
			// 아래줄은 ) 만 있는 경우임.
			else return false;
		}
	}
	//아래줄은 (는 있는데, 아무것도 안들어오는 상태.
	// 스택이 비어있으면 True / 차있으면 False 반환
	return stk.empty();
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (check(s)) cout << "YES\n";
		else cout << "NO\n";
	}
}