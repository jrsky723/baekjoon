#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int graph[302][302];
int n, m, t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> t;

  for (int i = 1; i <= n; i++)
    fill(graph[i] + 1, graph[i] + 1 + n, INF);
  while (m--) {
    int u, v, h;
    cin >> u >> v >> h;
    graph[u][v] = h;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (graph[i][j] > max(graph[i][k], graph[k][j])) {
          graph[i][j] = max(graph[i][k], graph[k][j]);
        }
      }
    }
  }
  while (t--) {
    int u, v;
    cin >> u >> v;
    if (graph[u][v] == INF) cout << -1 << '\n';
    else cout << graph[u][v] << '\n';
  }
}