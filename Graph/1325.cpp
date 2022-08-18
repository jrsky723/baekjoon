#include <bits/stdc++.h>
using namespace std;
vector<int> dir[10005];
bool vis[10005];
int point[10005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    dir[v].push_back(u);
  }
  int mx = 0;
  for (int st = 1; st <= n; st++) {
    queue<int> q;
    fill(vis + 1, vis + 1 + n, 0);
    q.push(st);
    vis[st] = true;
    while (!q.empty()) {
      int cur = q.front(); q.pop(); point[st]++;
      for (auto nxt : dir[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        q.push(nxt);
      }
    }
    mx = max(point[st], mx);
  }
  for (int i = 1; i <= n; i++)
    if (point[i] == mx) cout << i << ' ';
}