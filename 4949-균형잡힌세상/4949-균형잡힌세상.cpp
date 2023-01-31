// https://www.acmicpc.net/problem/4949
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		// 띄어쓰기로 계속 들어올 때는 string s를 안쪽에 넣는다. 
		string s;
		getline(cin, s);
		if (s == ".") break;
		// 문자 -> 숫자로 ASCII 코드로 들어오게 stack을 int 타입으로 선언
		stack<int> stk;
		bool check = true;
		// s는 입력 한줄. ;; 체크해서 pop 하는 부분 
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ')') {
				// 스택이 비어있지 않고, 
				if (stk.size() == 0 || stk.top() == '[') {
					check = false;
					break;
				} else stk.pop();
			}
			if (s[i] == ']') {
				if (stk.size() == 0 || stk.top() == '(') {
					check = false;
					break;
				} else stk.pop();
			}
			// push하는 부분 
			if (s[i] == '(') stk.push(s[i]);
			if (s[i] == '[') stk.push(s[i]);
		}
		if (stk.size() == 0 && check) cout << "yes\n";
		else cout << "no\n";
	}
}