#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int INF = 0x3f3f3f3f;
int bully[502];
pair<int, int> bulPair[502];
pair<int, int> d[502][502];  //거리, 경로중 가장 큰 도시

int getBul(pair<int, int> &p) { return p.X + bully[p.Y]; }
int getBul(pair<int, int> &p1, pair<int, int> &p2) {
  if (bully[p1.Y] > bully[p2.Y])
    return p1.X + p2.X + bully[p1.Y];
  else
    return p1.X + p2.X + bully[p2.Y];
}
int n, m, q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> bully[i];
    bulPair[i].X = bully[i];
    bulPair[i].Y = i;
  }
  sort(bulPair + 1, bulPair + 1 + n);  // bulPair를 오름차순
  for (int i = 1; i <= n; i++) fill(d[i] + 1, d[i] + 1 + n, make_pair(INF, 0));

  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (bully[a] < bully[b]) swap(a, b);
    d[a][b] = {min(d[a][b].X, c), a};
    d[b][a] = {min(d[b][a].X, c), a};
  }
  for (int i = 1; i <= n; i++) d[i][i] = {0, 0};

  for (int l = 1; l <= n; l++) {
    int k = bulPair[l].Y;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (getBul(d[i][j]) > getBul(d[i][k], d[k][j])) {
          d[i][j].X = d[i][k].X + d[k][j].X;
          if (bully[d[i][k].Y] > bully[d[k][j].Y])
            d[i][j].Y = d[i][k].Y;
          else
            d[i][j].Y = d[k][j].Y;
        }
      }
    }
  }
  while (q--) {
    int s, t;
    cin >> s >> t;
    if (getBul(d[s][t]) >= INF)
      cout << -1 << '\n';
    else
      cout << getBul(d[s][t]) << '\n';
  }
}
