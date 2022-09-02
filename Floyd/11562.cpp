#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int d[252][252];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) fill(d[i] + 1, d[i] + 1 + n, INF);
  while (m--) {
    int u, v, b;
    cin >> u >> v >> b;
    d[u][v] = 0;
    d[v][u] = b ? 0 : 1;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
       if (i == j) d[i][j] = 0;
       d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    cout << d[u][v] << '\n';
  }
}