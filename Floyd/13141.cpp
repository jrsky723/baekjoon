#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int d[202][202];
int t[202];
vector<tuple<int, int, int>> edge;
int n, m;
double ans = INF;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) fill(d[i] + 1, d[i] + 1 + n, INF);
  while (m--) {
    int s, e, l;
    cin >> s >> e >> l;
    edge.push_back({s, e, l});
    d[s][e] = min(d[s][e], l);
    d[e][s] = min(d[e][s], l);
  }

  for (int i = 1; i <= n; i++) d[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  
  for (int i = 1; i <= n; i++) {
    fill(t + 1, t + 1 + n, 0);
    for (int j = 1; j <= n; j++) t[j] = d[i][j];
    double temp = 0;
    for (int j = 0; j < edge.size(); j++) {
      int s, e, l;
      tie(s, e, l) = edge[j];
      l += min(t[s], t[e]);
      double t1 = max(t[s], t[e]);
      double t2 = (double)(l - t1) / (double)2;
      if (t2 < 0) t2 = 0;
      temp = max(temp, t1 + t2);
    }
    ans = min(ans, temp);
  }
  cout << fixed;
  cout.precision(1);
  cout << ans;
}