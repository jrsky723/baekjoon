#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int graph[202][202];
int nxt[202][202];
int n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) fill(graph[i] + 1, graph[i] + 1 + n, INF);
  while (m--) {
    int a, b, t;
    cin >> a >> b >> t;
    if (graph[a][b] > t) {
      graph[a][b] = t;
      graph[b][a] = t;
      nxt[a][b] = b;
      nxt[b][a] = a;
    }
  }
  for (int i = 1; i <= n; i++) graph[i][i] = 0;

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (graph[i][j] > graph[i][k] + graph[k][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (nxt[i][j])
        cout << nxt[i][j] << ' ';
      else
        cout << "- ";
    }
    cout << '\n';
  }
}