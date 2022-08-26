#include <bits/stdc++.h>
using namespace std;
int t[1002], deg[1002], dp[1002];
vector<int> adj[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> t[i];
      dp[i] = 0;
      adj[i].clear();
      deg[i] = 0;
    }
    while (k--) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      deg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if(deg[i] == 0) {
      q.push(i);
      dp[i] = t[i];
    }
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      for (auto nxt : adj[cur]) {
        deg[nxt]--;
        dp[nxt] = max(dp[nxt], dp[cur] + t[nxt]);
        if (deg[nxt] == 0) q.push(nxt);
      }
    }
    int w;
    cin >> w;
    cout << dp[w] << '\n';
  }
}