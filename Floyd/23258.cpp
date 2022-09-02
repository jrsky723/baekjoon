#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int d[302][302][302];
int n, q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 0; k <= n; k++) d[i][j][k] = INF;

  for (int i = 1; i <= n; i++) {
    for (int k = 0; k <= n; k++) d[i][i][k] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int num;
      cin >> num;
      if (num) d[i][j][0] = num;
    }
  }

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j][k] = min(d[i][j][k - 1], (d[i][k][k - 1] + d[k][j][k - 1]));

  while (q--) {
    int c, s, e;
    cin >> c >> s >> e;
    if (d[s][e][c - 1] == INF)
      cout << -1 <<'\n';
    else
      cout << d[s][e][c - 1] << '\n';
  }
}