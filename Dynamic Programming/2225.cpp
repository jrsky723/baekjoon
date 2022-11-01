#include<bits/stdc++.h>
using namespace std;

int N, K;
long long MOD = 1000000000;
long long dp[205][205];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;

  fill(dp[1], dp[1] + 1 + N, 1);

  for (int k = 2; k <= K; k++) {
    for (int n = 0; n <= N; n++) {
      for (int i = 0; i <= n; i++) dp[k][n] += dp[k - 1][i];
      dp[k][n] %= MOD;
    }
  }
  cout << dp[K][N];
}