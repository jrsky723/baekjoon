#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n;
vector<int> adj[MAX + 5];
int dist[MAX + 5];

void dfs(int cur, int pre) {
  dist[cur] = dist[pre] + 1;
  for (auto nxt : adj[cur]) {
    if(nxt == pre) continue;
    dfs(nxt, cur);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,0);
  vector<int> cars;
  for (int i = 1; i <= n; i++) {
    bool isCar;
    cin >> isCar;
    if(isCar) cars.push_back(dist[i]);
  } 
  sort(cars.rbegin(), cars.rend());
  int ans = 0, t = 0;
  for (int d : cars) ans = max(ans, d + t++);
  cout << ans;
}