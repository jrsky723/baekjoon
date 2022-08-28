#include <bits/stdc++.h>
using namespace std;

vector<int> p(100002, -1);

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

tuple<int,int,int> edge[1000002];
int e, n, m;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  while(m--) {
    int a, b, cost;
    cin >> a >> b >> cost;
    edge[e++] = {cost, a, b};
  }
  sort(edge, edge + e);
  vector<int> road;
  for (int i = 0; i < e; i++) {
    int a, b, cost;
    tie(cost, a, b) = edge[i];
    if(!is_diff_group(a, b)) continue;
    road.push_back(cost);
  }
  int ans = 0;
  for (int i = 0; i < road.size() - 1; i++) ans += road[i];
  cout << ans;
}