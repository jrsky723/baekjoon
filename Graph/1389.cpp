#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int dist[101];
int point[101];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int st = 1; st <= n; st++) {
    queue<int> q;
    fill(dist + 1, dist + 1 + n, -1);
    q.push(st);
    dist[st] = 0;
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      point[st] += dist[cur];
      for (auto nxt : adj[cur]) {
        if (dist[nxt] >= 0) continue;
        dist[nxt] = dist[cur] + 1;
        q.push(nxt);
      }
    }
  }
  cout << min_element(point + 1, point + n) - point;
}