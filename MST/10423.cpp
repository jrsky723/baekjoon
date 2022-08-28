
#include <bits/stdc++.h>
using namespace std;

vector<int> p(1002, -1);

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<tuple<int, int, int>> edge;
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> temp;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    temp.push_back(x);
  }

  for (int i = 0; i < k - 1; i++) is_diff_group(temp[i], temp[i + 1]);

  for (int i = 0; i < m; i++) {
    int a, b, cost;
    cin >> a >> b >> cost;
    edge.push_back({cost, a, b});
  }

  sort(edge.begin(), edge.end());

  int ans = 0;
  for (int i = 0; i < edge.size(); i++) {
    int cost, a, b;
    tie(cost, a, b) = edge[i];
    if (!is_diff_group(a, b)) continue;
    ans += cost;
  }
  cout << ans;
}