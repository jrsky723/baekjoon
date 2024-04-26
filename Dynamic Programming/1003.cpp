#include <bits/stdc++.h>

using namespace std;

const int MAX = 40;

int dp[MAX + 5][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  dp[0][0] = 1;
  dp[1][1] = 1;

  for (int i = 2; i <= MAX; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
    dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
  }

  int tc;
  cin >> tc;

  while (tc--) {
    int n;
    cin >> n;
    cout << dp[n][0] << ' ' << dp[n][1] << '\n';
  }
}