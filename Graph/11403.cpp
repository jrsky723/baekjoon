#include <bits/stdc++.h>
using namespace std;

bool adj[101][101];
bool vis[101];
bool ans[101][101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> adj[i][j];
  
  for (int i = 1; i <= n; i++) {
    queue<int> q;
    fill(vis + 1, vis + 1 + n, 0);
    q.push(i);
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      for (int nxt = 1; nxt <= n; ++nxt) {
        if (!adj[cur][nxt] || vis[nxt]) continue;
        vis[nxt] = true;
        ans[i][nxt] = 1;
        q.push(nxt);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) cout << ans[i][j] << ' ';
    cout << '\n';
  }
}