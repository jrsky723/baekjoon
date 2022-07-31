#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
int mx;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dp[num] = dp[num - 1] + 1;
        mx = max(dp[num], mx);
    }
    cout << n - mx;
}