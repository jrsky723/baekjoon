#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int goodCnt = 0;
    int t;
    stack <char> stk;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        for (char c : s) {
            if (stk.empty() || stk.top() != c) stk.push(c);
            else stk.pop();
        }
        if (stk.empty()) goodCnt++;
        while (!stk.empty()) stk.pop(); //스택을 안에다가 새로 생성해도된다.
    }
    cout << goodCnt;
}

//정답과 동일