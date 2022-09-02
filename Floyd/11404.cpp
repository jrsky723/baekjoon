#include <bits/stdc++.h>
using namespace std;

const int INF = 10000001;
int d[102][102];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) 
    fill(d[i] + 1, d[i] + 1 + n, INF);
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    d[a][b] = min(c, d[a][b]);
  }
  for (int i = 1; i <= n; i++) d[i][i] = 0;
  for (int k = 1; k <= n; k++) {
    for (int s = 1; s <= n; s++) {
      for (int t = 1; t <= n; t++) {
        d[s][t] = min(d[s][t], d[s][k] + d[k][t]);
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == INF) d[i][j] = 0;
      cout << d[i][j] << ' ';
    }
    cout<<'\n';
  }
}