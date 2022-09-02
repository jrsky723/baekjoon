#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[102][102];
int t[102], sum[102];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m, r;
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) 
    fill(d[i] + 1, d[i] + 1 + n, INF);
  while (r--) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = d[b][a] = c;
  }
  for (int i = 1; i <= n; i++) d[i][i] = 0;

  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (d[i][j] <= m) sum[i] += t[j];
  cout << *max_element(sum + 1, sum + 1 + n);
}