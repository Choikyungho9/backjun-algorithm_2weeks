//https://www.acmicpc.net/problem/1436
#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int i = 666;
    // for(; ; i++)은 무한 루프
    for (;; i++) {
        if (to_string(i).find("666") != string::npos)n--;
        if (n == 0)break;
    }
    cout << i << "\n";
}