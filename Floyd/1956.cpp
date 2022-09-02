#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[401][401];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int v, e;
  cin >> v >> e;
  for (int i = 1; i <= v; i++) fill(d[i] + 1, d[i] + 1 + v, INF);
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
  }
  int ans = INF;
  for (int k = 1; k <= v; k++)
    for (int i = 1; i <= v; i++)
      for (int j = 1; j <= v; j++)
        if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];

  for (int i = 1; i <= v; i++) ans = min(ans, d[i][i]);

  if (ans == INF) cout << -1;
  else cout << ans;
}