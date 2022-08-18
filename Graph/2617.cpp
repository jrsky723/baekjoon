#include <bits/stdc++.h>
using namespace std;
vector<int> bigger[101];
bool vis[101];
int heavy[101];  //무거운 v갯수
int light[101];  //가벼운 v갯수
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    bigger[u].push_back(v);
  }
  for (int st = 1; st <= n; st++) {
    queue<int> q;
    fill(vis + 1, vis + 1 + n, 0);
    vis[st] = true;
    q.push(st);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto nxt : bigger[cur]) {
        if (vis[nxt]) continue;
        light[st]++;
        heavy[nxt]++;
        vis[nxt] = true;
        q.push(nxt);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (heavy[i] > (n - 1) / 2 || light[i] > (n - 1) / 2) ans++;
  cout << ans;
}