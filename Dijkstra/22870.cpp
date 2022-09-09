#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
const int INF = 0x3f3f3f3f;
vector <pair<int, int>> adj[MAX + 5];
int d[MAX + 5];
bool chk[MAX + 5];
int n, m, s, e;

void dijkstra(int st) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, 
    greater<pair<int, int>>> pq;
  fill(d + 1, d + 1 + n, INF);
  d[st] = 0;
  pq.push({d[st], st});
  while(!pq.empty()) {
    auto [cDist, cNode] = pq.top(); pq.pop();
    if (d[cNode] != cDist) continue;
    for (auto [nNode, nDist] : adj[cNode]){
      if(chk[nNode] || d[nNode] <= d[cNode] + nDist) continue;
      d[nNode] = d[cNode] + nDist;
      pq.push({d[nNode], nNode});
    }
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
  cin >> s >> e;
  dijkstra(e);
  int left = 0, cur = s;
  while(cur != e) {
    for (auto [nNode, nDist] : adj[cur]){
      if (left + nDist + d[nNode] == d[s]){
        left += nDist;
        chk[nNode] = true;
        cur = nNode;
        break;
      }
    }
  }
  chk[e] = 0;
  dijkstra(s);
  cout << left + d[e];
}