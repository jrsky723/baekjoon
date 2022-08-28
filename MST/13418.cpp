#include <bits/stdc++.h>
using namespace std;

vector<int> p(1002);

int find(int x) {
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

tuple<int, int, int> edge[500000];

int n, m, e;
  
int mst() {
  fill(p.begin(), p.end(), -1);
  int cnt = 0, ret = 0;
  for (int i = 0; i < e; i++) {
    int a, b, up;
    tie(up, a, b) = edge[i];
    if(!is_diff_group(a, b)) continue;
    cnt++;
    ret += up;
    if (cnt == n) break;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;

  for (int i = 0; i < m + 1; i++) {
    int a, b, up;
    cin >> a >> b >> up;
    up = up ? 0 : 1;
    edge[e++] = {up, a, b};
  }
  sort(edge + 1, edge + 1 + m);
  int mn = mst();
  sort(edge + 1, edge + 1 + m, [](auto &a, auto &b){return a > b;});
  int mx = mst();
  cout << (mx * mx) - (mn * mn);
}