#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int REM = 10007;

int dp[MAX + 5];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= MAX; i++) {
    dp[i] = (dp[i - 2] + dp[i - 1]) % REM;
  }
  cout << dp[n] << '\n';
}