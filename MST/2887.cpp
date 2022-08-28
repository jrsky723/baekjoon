#include <bits/stdc++.h>
using namespace std;

#define X first
#define I second

vector<int> p(100005, -1);
pair<int, int> pos[3][100005];
int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return 0;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v])
    p[v] = u;
  else
    p[u] = v;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    pos[0][i - 1] = {x, i}, pos[1][i - 1] = {y,i}, pos[2][i - 1] = {z,i};
  }
  for (int i = 0; i < 3; i++) sort(pos[i], pos[i] + n);
  vector<tuple<int, int, int>> edge;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n - 1; j++) {
      edge.push_back({pos[i][j+1].X - pos[i][j].X, pos[i][j+1].I, pos[i][j].I});
    }
  }
  sort(edge.begin(),edge.end());
  long long ans = 0;
  for (int i = 0; i < edge.size(); i++){
    int cost, a, b;
    tie(cost, a, b) = edge[i];
    if (!is_diff_group(a, b)) continue;
    ans += cost;
  }
  cout << ans;
}