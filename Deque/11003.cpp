#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    deque <pair<int,int>> dq; 
    
    for (int i = 1; i < N + 1; i++) {
        int A;
        cin >> A;
        while (!dq.empty() && dq.back().first >= A)
            dq.pop_back();
        dq.push_back({ A,i });
        while (dq.front().second < i - L + 1)
            dq.pop_front();
        cout << dq.front().first << " ";
    }
}
//정답과 동일