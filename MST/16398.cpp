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

tuple<int,int,int> edge[1000002];
int e, n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int cost;
      cin >> cost;
      edge[e++] = {cost, i, j};
    }
  }
  sort(edge, edge + n*n);
  int cnt = 0;
  long long ans = 0;
  for (int i = 0; i < e; i++) {
    int a, b, cost;
    tie(cost, a, b) = edge[i];
    if (!is_diff_group(a, b)) continue;
    ans += cost;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << ans;
}