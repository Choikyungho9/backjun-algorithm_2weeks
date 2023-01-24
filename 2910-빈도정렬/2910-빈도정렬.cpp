// https://www.acmicpc.net/problem/2910
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int n, c, a[1004];

vector<pair<int, int>> v;

// mp는 카운팅 배열 ,, mp_first 는 첫번째수를 받음.
map<int, int> mp, mp_first;


bool cmp(pair<int, int> a, pair<int, int> b) {
	// 카운팅이 같다면 
	if (a.first == b.first) {
		// 먼저 나온거 우선
		return mp_first[a.second] < mp_first[b.second];
	}
	// 큰 것부터 반환하게
	return a.first > b.first;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	// a는 2 1 2 1 2 배열
	// mp는 2, 1 카운팅 배열 
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		mp[a[i]]++;
		// mp는 카운트(빈도수) // mp_first는 첫번째수 
		if (mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
	}
	for (auto it : mp) {
		v.push_back({ it.second, it.first });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) {
		for (int j = 0; j < i.first; j++) {
			cout << i.second << " ";
		}
	}

	return 0;
}
