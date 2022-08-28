#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define X first
#define Y second
vector<int> p(1002, -1);

int find(int x){
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v){
  u = find(u), v = find(v);
  if (u == v) return 0;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

double getDist(pair<int, int> p1, pair<int, int> p2){
  long long x = p1.X - p2.X;
  long long y = p1.Y - p2.Y;
  return sqrt(x*x + y*y);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  
  vector<tuple<double, int, int>> edge;
  vector<pair<int, int>> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    pos[i] = {x, y};
  }
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if(is_diff_group(a, b)) cnt++;
  }
  
  for (int i = 1; i <= n - 1; i++){
    for (int j = i + 1; j <= n; j++){
      double dist = getDist(pos[i], pos[j]);
      edge.push_back({dist, i, j});
    } 
  }
  sort(edge.begin(), edge.end());
  long double ans = 0;
  for (int i = 0; i < edge.size(); i++){
    double dist;
    int a, b;
    tie(dist, a, b) = edge[i];
    if (!is_diff_group(a, b)) continue;
    ans += dist;
    cnt++;
    if (cnt == n - 1) break;
  }
  cout << fixed;
  cout.precision(2);
  cout << round(ans * 100) / 100;
}