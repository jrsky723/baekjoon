#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
int adj[16][16];
int dp[16][1 << 16];
int n;

int dfs(int cur, int curBit) {
  if (curBit == (1 << n) - 1) {
    if (adj[cur][0])
      return adj[cur][0];
    else
      return INF;
  }
  if (dp[cur][curBit] != -1) return dp[cur][curBit];

  dp[cur][curBit] = INF;
  
  for (int i = 1; i < n; i++) {
    if (adj[cur][i] == 0 || curBit & (1 << i)) continue;
    dp[cur][curBit] =
        min(dp[cur][curBit], dfs(i, curBit | (1 << i)) + adj[cur][i]);
  }
  return dp[cur][curBit];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    fill(dp[i], dp[i] + (1 << n), -1);
    for (int j = 0; j < n; j++) cin >> adj[i][j];
  }
  cout << dfs(0, 1);
}