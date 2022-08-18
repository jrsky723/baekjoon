#include <bits/stdc++.h>
using namespace std;
vector<int> adj[51];
int dist[51];
int point[51];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int u, v;
  cin >> u >> v;
  while (u != -1 && v != -1) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cin >> u >> v;
  }
  for (int st = 1; st <= n; st++) {
    queue<int> q;
    fill(dist + 1, dist + 1 + n, -1);
    q.push(st);
    dist[st] = 0;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      for(auto nxt : adj[cur]){
        if (dist[nxt] >= 0) continue;
        q.push(nxt);
        dist[nxt] = dist[cur] + 1;
      }
    }
    point[st] = *max_element(dist + 1, dist + 1 + n);
  }
  int score = *min_element(point + 1, point + 1 + n);
  vector<int> cand;
  for (int i = 1; i <= n; i++) if (score == point[i]) cand.push_back(i);
  cout << score << ' ' << cand.size() << '\n';
  for (auto i : cand) cout << i << ' ';
}