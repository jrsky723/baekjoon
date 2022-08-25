#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000'000;
set<int> adj[MAX + 2];
int dp[MAX + 2][2];
bool vis[MAX + 2];

void dfs(int cur) {
  dp[cur][1] = 1;
  vis[cur] = true;
  for (auto nxt : adj[cur]){
    if (vis[nxt]) continue;
    dfs(nxt);
    dp[cur][0] += dp[nxt][1];
    dp[cur][1] += min(dp[nxt][0], dp[nxt][1]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  dfs(1);
  cout << min(dp[1][0], dp[1][1]);
}