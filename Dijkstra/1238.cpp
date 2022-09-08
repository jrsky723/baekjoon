#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e, target;
const int INF = 0x3f3f3f3f;
int d[1002], res[1002];
vector<pair<int, int>> adj[1002];

void dijkstra(int st) {
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  fill(d + 1, d + v + 1, INF);
  d[st] = 0;
  pq.push({ d[st],st });
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    if (d[cur.Y] != cur.X) continue;
    for (auto nxt : adj[cur.Y]) {
      if (d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({ d[nxt.Y], nxt.Y });
    }
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> v >> e >> target;
  while (e--) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({ c,v });
  }
  for (int i = 1; i <= v; i++) {
    dijkstra(i);
    res[i] = d[target];
  }
  dijkstra(target);
  for (int i = 1; i <= v; i++) res[i] += d[i];
  cout << *max_element(res + 1, res + v + 1);
}